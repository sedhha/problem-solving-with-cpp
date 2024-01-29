const threeSum = (array, target) => {
    array = array.sort((a, b) => a - b);


    for (let i = 0; i < array.length; i++) {
        const firstItem = array[i];
        let startPointer = i + 1;
        let endPointer = array.length - 1;
        for (let j = i + 1; j < array.length; j++) {
            if (startPointer >= endPointer) break;
            const midItem = array[startPointer]; // 1
            const lastItem = array[endPointer]; // 
            const sum = firstItem + midItem + lastItem;
            if (sum === target) {
                console.log(`Target Found: [${firstItem}, ${midItem}, ${lastItem}]`);
                startPointer++;
                endPointer--;
            }
            else if (sum > target) endPointer--;
            else startPointer++;
        }
    }
}

const sampleArray = [1, -1, 2, -2, 3, -3, 4, -4, 0];
// sorted Array: [-4, -3, -2, -1, 0, 1, 2, 3, 4] [-4 0 4]
// startPointer: 3
// endPointer: 8
// midTerm: -3 4
// j: 1 2 3 4 5 6 7 8
const target = 0;

threeSum(sampleArray, target);