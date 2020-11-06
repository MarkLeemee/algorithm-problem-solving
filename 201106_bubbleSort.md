Q
 - 버블 정렬 알고리즘을 활용하여 주어지는 배열을 오름차순으로 정렬하시오.

 

A
 - 정렬할 때 앞뒤 요소를 바꾸는 swap 기능을 ES6 전까지는 별도로 swap 함수를 만들어서 활용하였습니다. 하지만 ES6에서는 이하와 같이 보다 획기적인 방법이 등장하였습니다. 
```js
let a = 5, b = 6;
[a, b] = [b, a];
console.log(`${a} ${b}`);  // 6 5

let arr = [1, 2, 3, 4];
[arr[2], arr[3]] = [arr[3], arr[2]];
console.log(arr);  // [1, 2, 4, 3]
```

 - 이를 활용하면 버블정렬은 2중 for문으로 손 쉽게 해결됩니다. 간단하게 앞뒤 비교를 해서 크면 뒤로 보내고, 이를 배열 길이만큼 반복하면 됩니다.

 - 이를 보다 효율적으로 구현하려면 배열길이만큼 반복하지 않고, swap이 일어나는 횟수만큼만 반복해주면 정렬이 완성됩니다.

```js
const bubbleSort = function (arr) {
  for (let x = 0; x < arr.length; x++) {
    for (let i = 0; i < arr.length - 1; i++) {
      if (arr[i] > arr[i + 1]) {
        [arr[i], arr[i + 1]] = [arr[i + 1], arr[i]];
      }
    }
  }
  return arr;
}
```

```js
const bubbleSort = function (arr) {
  let cnt = 0;
  for (let c = 0; c <= cnt; c++) {
    for (let i = 0; i < arr.length - 1; i++) {
      if (arr[i] > arr[i + 1]) {
        [arr[i], arr[i + 1]] = [arr[i + 1], arr[i]];
        cnt++;
      }
    }
  }
  return arr;
}
```
