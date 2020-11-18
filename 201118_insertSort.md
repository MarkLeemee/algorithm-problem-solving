Q
 - 정수를 요소로 갖는 배열을 오름차순으로 정렬하여 리턴시키시오.

 - 삽입정렬로 구현되어야 하며, sort 메서드를 사용하면 안됩니다.

 - 두번째 인자로 callback 함수를 받아, 함수의 리턴값을 기준으로 정렬해보시오.

 

A
 - 삽입정렬 로직은 각각의 요소를 넣을 때부터 정렬 된 순서에 삽입하여, 항시 정렬된 상태를 갖도록 하는 것입니다. 즉, 첫번째 요소부터 비교하여 해당 값이 정렬된 위치에 들어가도록 만드는 것입니다.

 - 배열에서 특정 위치에 삽입하기 위해서 push가 아닌 splice 메서드를 활용하였습니다. 또한, 런타임 및 인덱스 변수 에러가 발생할 수 있으니, 제일 첫번째 요소와 마지막 요소 비교는 별도로 조건문을 넣어서 설정해주었습니다.

 - 별도의 callback 함수를 활용하여 정렬의 기준 혹은 변환된 값으로 정렬을 활용할 수도 있습니다.

```js
const insertionSort = function (arr) {
  let result = [arr[0]];
  for (let i = 1; i < arr.length; i++) {
    if (arr[i] < result[0]) {
      result.splice(0, 0, arr[i]);
      continue;
    } else if (arr[i] > result[result.length - 1]) {
      result.splice(result.length, 0, arr[i]);
      continue;
    }
    for (let n = 0; n < result.length - 1; n++) {
      if (arr[i] > result[n] && arr[i] <= result[n + 1]) {
        result.splice(n + 1, 0, arr[i]);
      }
    }
  }
  return result;
};
```

```js
const insertionSort = function (arr, callback) {
  let result = [arr[0]];
  for (let i = 1; i < arr.length; i++) {
    if (callback(arr[i]) < callback(result[0])) {
      result.splice(0, 0, arr[i]);
      continue;
    } else if (callback(arr[i]) > callback(result[result.length - 1])) {
      result.splice(result.length, 0, arr[i]);
      continue;
    }
    for (let n = 0; n < result.length - 1; n++) {
      if (callback(arr[i]) > callback(result[n]) && callback(arr[i]) <= callback(result[n + 1])) {
        result.splice(n + 1, 0, arr[i]);
      }
    }
  }
  return result;
};
```
