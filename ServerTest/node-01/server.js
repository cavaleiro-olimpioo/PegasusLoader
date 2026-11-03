import express from 'express';
import { join } from 'node:path'

const app = express()
const name = 'node-01'
const port = 3001
const path = 'raíz'


app.get('/', (req, res) => {
    res.set($`Bem vindo ao servidor! Você se está no ${name}, no path ${path}`)
    res.sendFile(join(process.cwd(), 'index.html'))
})

app.listen(port, () => {
    console.log(`${name} rodando na porta ${port}`)
})