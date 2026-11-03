import express from 'express';

const app = express();
const name = process.env.NAME || 'servidor';
const port = process.env.PORT || 3000;

app.get('/', (req, res) => {
  res.set('X-Servidor ', name);
  res.send(`Bem-vindo! Você está no ${name}\n`);
});

app.listen(port, () => console.log(`${name} rodando na porta ${port}`));