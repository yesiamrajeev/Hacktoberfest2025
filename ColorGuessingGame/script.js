const rgbValue = document.getElementById('rgbValue');
const colorOptions = document.getElementById('colorOptions');
const result = document.getElementById('result');
const resetBtn = document.getElementById('resetBtn');

let correctColor;

function randomColor() {
    const r = Math.floor(Math.random() * 256);
    const g = Math.floor(Math.random() * 256);
    const b = Math.floor(Math.random() * 256);
    return `rgb(${r}, ${g}, ${b})`;
}

function generateColors() {
    colorOptions.innerHTML = '';
    const correctIndex = Math.floor(Math.random() * 3);
    correctColor = randomColor();
    rgbValue.textContent = correctColor.toUpperCase();

    for (let i = 0; i < 3; i++) {
        const btn = document.createElement('button');
        if (i === correctIndex) {
            btn.style.backgroundColor = correctColor;
            btn.dataset.correct = "true";
        } else {
            const color = randomColor();
            btn.style.backgroundColor = color;
            btn.dataset.correct = "false";
        }
        btn.addEventListener('click', checkColor);
        colorOptions.appendChild(btn);
    }
    result.textContent = '';
}

function checkColor(e) {
    if (e.target.dataset.correct === "true") {
        result.textContent = "Correct! 🎉";
    } else {
        result.textContent = "Wrong! Try again 😢";
    }
}

resetBtn.addEventListener('click', generateColors);

// Initialize game
generateColors();
