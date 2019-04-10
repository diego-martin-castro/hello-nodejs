const http = require('http');
const addon = require('./build/Release/addon');

const hostname = '127.0.0.1';
const port = 3000;

var hello = addon.hello();

const server = http.createServer((req, res) => {
res.statusCode = 200;
res.setHeader('Content-Type', 'text/html');
res.write('<h1>esto es un ' + hello.foo.bar + '</h1>');
res.end();
});

server.listen(port, hostname, () => {
    console.log(`Server running at http://${hostname}:${port}/`);
    console.log(JSON.stringify(hello));
});

/*
fs = require('fs');

fs.readFile('./hello.html', function (err, html) {
    if (err) {
        throw err; 
    }

    const hostname = '127.0.0.1';
    const port = 3000;

    const server = http.createServer((req, res) => {
    res.statusCode = 200;
    res.setHeader('Content-Type', 'text/html');
    res.write(html);
    res.end();
    });

    server.listen(port, hostname, () => {
        console.log(`Server running at http://${hostname}:${port}/`);
    });

});
*/



