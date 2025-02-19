self.onmessage = function(event) {
    const n = event.data;
    const facts = factorial(n);
    self.postMessage(facts);
};

function factorial(n) {
    const facts = new Array(n-1);
    facts[0] = 1; 
    for (let i = 1; i <= n-1; i++) { 
        facts[i] = (i+1) * facts[i - 1]; 
    }
    return facts;
}