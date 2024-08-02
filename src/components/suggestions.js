const { spawn } = require('child_process');

function getSuggestions(query, callback) {
    const cppProcess = spawn('./autocomplete', [query]);

    cppProcess.stdout.on('data', (data) => {
        const suggestions = data.toString().trim().split('\n');
        callback(null, suggestions);
    });

    cppProcess.stderr.on('data', (data) => {
        callback(data.toString(), null);
    });

    cppProcess.on('close', (code) => {
        console.log(`child process exited with code ${code}`);
    });
}

module.exports = { getSuggestions };
