const app = require("express")();
const PORT = 8080;


app.get('/tshirt', (req, res) => {
    res.status(200).send({
        tshirt: '👕👕',
        size: 'medium'
        
    });
    res.send('tshirt');
});
app.listen(PORT, () => {
    console.log(`running on http://localhost:${PORT}`);
})