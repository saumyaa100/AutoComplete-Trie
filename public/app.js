document.getElementById('search-input').addEventListener('input', function() {
    const query = this.value;
    if (query.length >=1) {
        fetch(`/autocomplete?query=${query}`)
            .then(response => response.json())
            .then(data => {
                const suggestionsContainer = document.getElementById('suggestions');
                suggestionsContainer.innerHTML = '';
                data.suggestions.forEach(suggestion => {
                    const div = document.createElement('div');
                    div.classList.add('suggestion');
                    div.innerText = suggestion;
                    suggestionsContainer.appendChild(div);
                });
            });
    }
    else{
        const suggestionsContainer = document.getElementById('suggestions');
        suggestionsContainer.innerHTML = '';
    }
});
