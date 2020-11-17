Q
 - 입력받은 문자열의 각 문자를 가지고 만들 수 있는 모든 부분집합을 리턴하시오.

 - 중복된 원소(문자)를 허용하지 않으며, 결과는 알파벳 순으로 정렬되어야 합니다.

 - 부분집합은 빈 문자열을 포합합니다.

 

A
 - JS에서 중복된 값을 제거하는 방법은 여러 개가 있습니다. (링크참조) 여기서는 ES6의 Set 함수를 활용하여 중복되는 값을 제거한 (배열을 만들고 정렬하여) 새로운 문자열을 만들었습니다.

 - 부분집합의 생성은 재귀호출을 활용하였습니다. 빈 글자부터 1글자, 2글자, 3글자... 1글자씩 늘려가며 문자조합을 만드는 재귀함수를 활용하였습니다. 이때, 매개변수로 begin 값을 넣어서 중복값 및 정렬이 흐뜨러지지 않도록 잡았습니다.

```js
const powerSet = function (str) {
  const set = Array.from(new Set(str));
  set.sort();
  let newStr = set.join("");
  
  let result = [];
  function recursion(string, begin) {
    result.push(string);
    for(let i = begin; i < newStr.length; i++) {
      recursion(string+newStr[i], i + 1);
    }
  }
  
  recursion('', 0);
  return result;
};
```

 - 정렬된 배열과 reduce를 활용하여 중복된 값을 제거하였습니다. 정렬된 배열의 중복된 값은 순서가 붙어있으니, 이를 찾아 제거하는 로직입니다.

 - 여기서는 각각의 케이스(글자수)마다 전체 탐색을하여 마지막 조건문(문자열 마지막까지 탐색)시에 추가해주는 형태입니다. 이전 형태보다 전체탐색을 많이하기에 이전코드보다는 비효율적인 코드입니다.

```js
const powerSet = function (str) {
  const sorted = str.split('').sort();
  const deduplicated = sorted.reduce((acc, item) => {
    if (acc[acc.length - 1] === item) {
      return acc;
    } else {
      return acc.concat(item);
    }
  });

  let subSets = [];
  const pickOrNot = (idx, subset) => {
    if (idx === deduplicated.length) {
      subSets.push(subset);
      return;
    }
    pickOrNot(idx + 1, subset);
    pickOrNot(idx + 1, subset + deduplicated[idx]);
  };
  
  pickOrNot(0, '');
  return subSets.sort();
};
```
