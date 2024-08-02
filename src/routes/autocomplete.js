const express = require('express');
const router = express.Router();
const { getSuggestions } = require('../components/suggestions');

router.get('/autocomplete', (req, res) => {
    const query = req.query.query;
    getSuggestions(query, (err, suggestions) => {
        if (err) {
            res.status(500).json({ error: err });
        } else {
            res.json({ suggestions });
        }
    });
});

module.exports = router;
