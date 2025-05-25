class SortVisualizer {
  constructor() {
    this.array = [];
    this.arrayContainer = document.getElementById("array-container");
    this.newArrayBtn = document.getElementById("newArray");
    this.startSortBtn = document.getElementById("startSort");
    this.speedInput = document.getElementById("speed");
    this.sizeInput = document.getElementById("size");
    this.algorithmSelect = document.getElementById("algorithm");

    this.setupEventListeners();
    this.generateNewArray();
    this.updateAlgorithmExplanation();
  }

  setupEventListeners() {
    this.newArrayBtn.addEventListener("click", () => this.generateNewArray());
    this.startSortBtn.addEventListener("click", () => this.startSort());
    this.sizeInput.addEventListener("input", () => this.generateNewArray());
    this.algorithmSelect.addEventListener("change", () =>
      this.updateAlgorithmExplanation()
    );
  }

  updateAlgorithmExplanation() {
    const algorithm = this.algorithmSelect.value;
    document.querySelectorAll(".algorithm-explanation").forEach((el) => {
      el.style.display = "none";
    });
    document.getElementById(`${algorithm}Sort`).style.display = "block";
  }

  generateNewArray() {
    this.arrayContainer.innerHTML = "";
    this.array = [];
    const size = parseInt(this.sizeInput.value);

    for (let i = 0; i < size; i++) {
      const value = Math.floor(Math.random() * 100) + 1;
      this.array.push(value);
      const bar = document.createElement("div");
      bar.className = "bar";
      bar.style.height = `${value}%`;
      this.arrayContainer.appendChild(bar);
    }
  }
  async startSort() {
    this.newArrayBtn.disabled = true;
    this.startSortBtn.disabled = true;
    this.sizeInput.disabled = true;
    this.algorithmSelect.disabled = true;

    const algorithm = this.algorithmSelect.value;
    switch (algorithm) {
      case "merge":
        await this.mergeSort(0, this.array.length - 1);
        break;
      case "quick":
        await this.quickSort(0, this.array.length - 1);
        break;
      case "insertion":
        await this.insertionSort();
        break;
      case "selection":
        await this.selectionSort();
        break;
    }

    this.newArrayBtn.disabled = false;
    this.startSortBtn.disabled = false;
    this.sizeInput.disabled = false;
    this.algorithmSelect.disabled = false;

    // Mark all bars as sorted
    const bars = this.arrayContainer.children;
    for (let bar of bars) {
      bar.className = "bar sorted";
    }
  }

  async mergeSort(start, end) {
    if (start >= end) return;

    const mid = Math.floor((start + end) / 2);
    await this.mergeSort(start, mid);
    await this.mergeSort(mid + 1, end);
    await this.merge(start, mid, end);
  }

  async merge(start, mid, end) {
    const delay = 101 - this.speedInput.value;
    const bars = this.arrayContainer.children;

    const leftArray = this.array.slice(start, mid + 1);
    const rightArray = this.array.slice(mid + 1, end + 1);

    let i = start;
    let l = 0;
    let r = 0;

    while (l < leftArray.length && r < rightArray.length) {
      bars[i].className = "bar comparing";
      await this.sleep(delay);

      if (leftArray[l] <= rightArray[r]) {
        this.array[i] = leftArray[l];
        bars[i].style.height = `${leftArray[l]}%`;
        l++;
      } else {
        this.array[i] = rightArray[r];
        bars[i].style.height = `${rightArray[r]}%`;
        r++;
      }
      i++;
    }

    while (l < leftArray.length) {
      bars[i].className = "bar comparing";
      await this.sleep(delay);
      this.array[i] = leftArray[l];
      bars[i].style.height = `${leftArray[l]}%`;
      l++;
      i++;
    }

    while (r < rightArray.length) {
      bars[i].className = "bar comparing";
      await this.sleep(delay);
      this.array[i] = rightArray[r];
      bars[i].style.height = `${rightArray[r]}%`;
      r++;
      i++;
    }

    // Reset the color of bars in this section
    for (let j = start; j <= end; j++) {
      bars[j].className = "bar";
    }
  }

  async quickSort(start, end) {
    if (start >= end) return;

    // Set pivot as the last element
    const pivot = this.array[end];
    const bars = this.arrayContainer.children;
    let i = start - 1;

    // Partition around pivot
    for (let j = start; j < end; j++) {
      bars[j].className = "bar comparing";
      bars[end].className = "bar comparing";
      await this.sleep(101 - this.speedInput.value);

      if (this.array[j] <= pivot) {
        i++;
        // Swap elements
        [this.array[i], this.array[j]] = [this.array[j], this.array[i]];
        [bars[i].style.height, bars[j].style.height] = [
          bars[j].style.height,
          bars[i].style.height,
        ];
      }
      bars[j].className = "bar";
    }

    // Place pivot in correct position
    [this.array[i + 1], this.array[end]] = [this.array[end], this.array[i + 1]];
    [bars[i + 1].style.height, bars[end].style.height] = [
      bars[end].style.height,
      bars[i + 1].style.height,
    ];

    bars[end].className = "bar";

    // Recursively sort sub-arrays
    await this.quickSort(start, i);
    await this.quickSort(i + 2, end);
  }

  async insertionSort() {
    const bars = this.arrayContainer.children;
    const n = this.array.length;

    for (let i = 1; i < n; i++) {
      const key = this.array[i];
      const keyHeight = bars[i].style.height;
      let j = i - 1;

      bars[i].className = "bar comparing";
      await this.sleep(101 - this.speedInput.value);

      while (j >= 0 && this.array[j] > key) {
        bars[j].className = "bar comparing";
        bars[j + 1].className = "bar comparing";

        this.array[j + 1] = this.array[j];
        bars[j + 1].style.height = bars[j].style.height;

        await this.sleep(101 - this.speedInput.value);
        bars[j + 1].className = "bar";
        j--;
      }

      this.array[j + 1] = key;
      bars[j + 1].style.height = keyHeight;
      bars[i].className = "bar";
    }
  }

  async selectionSort() {
    const bars = this.arrayContainer.children;
    const n = this.array.length;

    for (let i = 0; i < n - 1; i++) {
      let minIdx = i;
      bars[i].className = "bar comparing";

      for (let j = i + 1; j < n; j++) {
        bars[j].className = "bar comparing";
        await this.sleep(101 - this.speedInput.value);

        if (this.array[j] < this.array[minIdx]) {
          bars[minIdx].className = "bar";
          minIdx = j;
          bars[minIdx].className = "bar comparing";
        } else {
          bars[j].className = "bar";
        }
      }

      if (minIdx !== i) {
        // Swap elements
        [this.array[i], this.array[minIdx]] = [
          this.array[minIdx],
          this.array[i],
        ];
        [bars[i].style.height, bars[minIdx].style.height] = [
          bars[minIdx].style.height,
          bars[i].style.height,
        ];
      }

      bars[minIdx].className = "bar";
      bars[i].className = "bar";
    }
  }

  sleep(ms) {
    return new Promise((resolve) => setTimeout(resolve, ms));
  }
}

// Initialize the visualizer when the page loads
window.addEventListener("load", () => {
  new SortVisualizer();
});
