const hashing = require("..")

let data = new Buffer.from("01000000f615f7ce3b4fc6b8f61e8f89aedb1d0852507650533a9e3b10b9bbcc30639f279fcaa86746e1ef52d3edb3c4ad8259920d509bd073605c9bf1d59983752a6b06b817bb4ea78e011d012d59d4", "hex");

const reverseBuffer = (buff) => {
    const reversed = new Buffer.alloc(buff.length);
    for (let i = buff.length - 1; i >= 0; i--)
        reversed[buff.length - i - 1] = buff[i];
    return reversed;
};

let hashedData = hashing.hash(data, 1024, 1, 1);
if (reverseBuffer(hashedData).toString('hex') == "0000000110c8357966576df46f3b802ca897deb7ad18b12f1c24ecff6386ebd9"){
    console.log("passed");
}else{
    console.log(reverseBuffer(hashedData).toString('hex'))
    console.log("failed");
}
