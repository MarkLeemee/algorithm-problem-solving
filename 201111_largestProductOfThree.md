Q
 - 정수를 갖는 배열을 입력받아 3개의 요소를 곱해 나올 수 있는 최대값을 리턴합니다.

 - 배열의 길이는 3 이상이며, 음수와 0을 포함합니다.


A
 - 입력배열이 양수로만 이뤄진 배열이라면 버블정렬을 활용하여 아주아주 쉽게 풀 수 있는 문제이다. 하지만 음수가 주어지는 경우라 이하 3가지 경우의 수로 나눠서 생각해보았다. 이렇게 3가지인 경우가 3개 요소의 곱이 가장 큰 경우이다. 이런식으로 모든 경우의 수를 설정하고 설계한다면 문제는 풀리겠지만 코드가 더러워질 가능성이 높다. 이것을 2번째 코드와 같이 단 5줄로 깔끔하게 만들어 버릴 수가 있다.

1. 양수로만 이뤄진 경우
2. 음수로만 이뤄진 경우
3. 음수의 절대값 2개가 양수의 no.1 or no.2보다 큰 경우

```js
const largestProductOfThree = function (arr) {
  const producOfThree = function(array_three) {
    let largestProduct = array_three.reduce((accu, curr) => {
      return accu * curr;
    }, 1);
    return largestProduct;
  };

  let sortedArr = arr.sort(function(a, b) {
    return Math.abs(b) - Math.abs(a);
  });

  let negative = sortedArr.filter(e => e < 0);
  let positive = sortedArr.filter(e => e >= 0);

  if (negative.length === 0) {
    return producOfThree(positive.slice(0, 3));
  } else if (positive.length === 0) {
    return producOfThree(negative.slice(-3));
  } else {
    absNegative = negative.filter(
      e => Math.abs(e) >= positive[0] || Math.abs(e) >= positive[1]
    );
    if (absNegative.length >= 2) {
      let array_three = [absNegative[0], absNegative[1], positive[0]];
      return producOfThree(array_three);
    } else {
      return producOfThree(positive.slice(0, 3));
    }
  }
};
```

 - 정말 깔끔한 코드다. 일단 내림차순으로 정렬을 한다. 이럴 경우 음수는 좌측이 양수는 우측으로 정렬되어진다. 그리고 깔끔하게 전부 다 양수인 경우와 음수2개 양수 1개인 경우의 곱을 비교해주면 된다. 

 - Problem Solving 시에 여러가지 알고리즘 기법들이 존재하지만, 어떤 기법을 쓰냐보다도 머리를 쓰는 것이 무엇보다 중요함을 느꼈다.

```js
const largestProductOfThree = function (arr) {
  const sorted = arr.slice().sort((a, b) => a - b);
  const len = arr.length;
  const candi1 = sorted[len - 1] * sorted[len - 2] * sorted[len - 3];
  const candi2 = sorted[len - 1] * sorted[0] * sorted[1];
  return Math.max(candi1, candi2);
};
```
