const decodeXOREDArray = (array, first) => {
    const decoded = [first]
    for (let i = 0; i < array.length; i++) {
        let decodedNumber = first ^ array[i];
        decoded.push(decodedNumber);
        first = decodedNumber;
    }
    return decoded;
}

const main = () => {
    const array = [1, 2, 3]
    const first = 1
    console.log(decodeXOREDArray(array, first))
}
main();