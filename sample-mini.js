const exp2 = []; // exp2[i] == 2**(i-1074)
exp2[1074] = 1.0;
for (let i = -1; i >= -1074; --i) {
    exp2[1074 + i] = exp2[1074 + i + 1] / 2.0;
}
for (let i = 1; i <= 1023; ++i) {
    exp2[1074 + i] = exp2[1074 + i - 1] * 2.0;
}
const split = (x) => {
    // Assumption: 0 < x < Infinity
    let i = -1074;
    while (exp2[i + 1074] <= x) {
        ++i;
    }
    --i;
    // 2**i <= x < 2**(i+1)
    // 2**52 <= x * 2**(52-i) < 2**53
    return [i, x * exp2[1074 + 52 - i]];
};

const HexFloat = (x) => {
    if (x === 0.0) {
        return 1.0 / x < 0.0 ? "-0x0p0" : "0x0p0";
    } else if (Number.isFinite(x)) {
        const [e, y] = split(Math.abs(x));
        const s = y.toString(16);
        const s1 = s.substring(0, 1);
        const s2 = s.match(/^(\w*[^0])0*$/)[1].substring(1);
        const sign = x < 0.0 ? "-" : "";
        return `${sign}0x${s1}${s2 === "" ? s2 : "." + s2}p${e}`;
    } else {
        // Infinity, NaN
        return x.toString();
    }
};

const print_float = (msg, x) => {
    console.log(`${msg}${x} [${HexFloat(x)}]`);
};

print_float("sin(4)=", Math.sin(4));
print_float("exp(-5.01)=", Math.exp(-5.01));
print_float("pow(4.7, -2.7)=", 4.7 ** (-2.7));
print_float("pow(0.6, -0.1)=", 0.6 ** (-0.1));
print_float("pow(17.21, 2.0)=", 17.21 ** 2.0);
print_float("pow(95.97, 2.0)=", 95.97 ** 2.0);
print_float("pow(75.7, 0.5)=", 75.7 ** 0.5);
