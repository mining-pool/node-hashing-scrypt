node-hashing-scrypt
===============

scrypt hashing functions for NodeJS(>=13).


Usage
-----

```javascript
const hashing = require('hashing-scrypt');

let data = new Buffer.from("7000000001e980924e4e1109230383e66d62945ff8e749903bea4336755c00000000000051928aff1b4d72416173a8c3948159a09a73ac3bb556aa6bfbcad1a85da7f4c1d13350531e24031b939b9e2b", "hex");

// Litecoin uses the scrypt factors (N=1024, r=1, p=1)
const N = 1024;
const R = 1;
const P = 1;
let hashedData = hashing.hash(data, N, R, P);

console.log(hashedData);

```