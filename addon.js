var addon = require('./build/Release/addon');
var hello = addon.hello();
console.log(hello.bar);
console.log(hello.foo.foo);
console.log(hello)
console.log(JSON.stringify(hello));