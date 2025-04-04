const calculateButton = document.getElementById('calculateButton');
const resultDisplay = document.getElementById('result');

if (window.Worker) {
    const worker = new Worker('worker.js');

    worker.onmessage = function(event) {
        const facts = event.data;
        resultDisplay.innerHTML = facts.map((fact, index) => `${index+1}! = ${fact}`).join('\n');
    };

    calculateButton.addEventListener('click', () => {
        const n = parseInt(document.getElementById('inputNumber').value);
        if (isNaN(n) || n <= 0) {
            resultDisplay.textContent = 'Please enter a integer greater than equal to 1.';
            return;
        }
        worker.postMessage(n);
    });
} else {
    resultDisplay.textContent = 'Your browser does not support web workers.';
}