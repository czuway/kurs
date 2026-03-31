const express = require('express');
const cors = require('cors');

const app = express();
const PORT = 5000;

app.use(cors());

function getSensorData() {
  return {
    temp: (20 + Math.random() * 10).toFixed(1),
    humidity: (40 + Math.random() * 20).toFixed(1),
    pressure: (1000 + Math.random() * 50).toFixed(0),
    waves: (1 + Math.random() * 2).toFixed(2)
  };
}

app.get('/data', (req, res) => {
  const data = getSensorData();
  console.log("Wysyłam dane:", data);
  res.json(data);
});

app.listen(PORT, () => {
  console.log(`Serwer działa na http://localhost:${PORT}`);
});