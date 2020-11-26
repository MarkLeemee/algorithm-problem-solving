Q
 - 입력받은 문자열의 모든 괄호의 짝이 맞는지 여부를 리턴하시오.

 - 괄호의 종류는 (), [], {}이며, 열리고 닫히는 순서가 맞아야 합니다. 

 

A
 - stack 자료구조를 개념을 활용하면 손쉽게 풀 수 있는 문제입니다. 입력받은 문자열을 순차적으로 stack에 쌓아주고 최상위 요소와 추가된 요소가 쌍이 맞으면 pop을 해주는 로직입니다. 문자열 전체를 순환하고 stack에 남은 요소가 없으면 괄호들이 쌍을 갖춘 경우임으로 true를 리턴합니다.

```js
const balancedBrackets = function (str) {
    let stack = [];
    for (let i = 0; i < str.length; i++) {
        if (stack.length !== 0) {
            upperElement = stack[stack.length - 1];
        }
        stack.push(str[i]);
        if (stack.length > 1) {
          if ((upperElement === '[' && stack[stack.length - 1] == ']') ||
              (upperElement === '{' && stack[stack.length - 1] == '}') ||
              (upperElement === '(' && stack[stack.length - 1] == ')')) {
              stack.pop();
              stack.pop();
          }
        }
    }
    if(stack.length === 0) {
      return true;
    } else {
      return false;
    }
};
```

 - 위 풀이와 로직은 같으나 js 객체 문법을 활용하여 풀이한 경우입니다. 몇 가지 경우의 수를 처리하지 못하기에 런타임 에러도 나고 가독성도 떨어지는 코드라 생각듭니다.

```js
const balancedBrackets = function (str) {
  const stack = [];
  const opener = {
    '{': '}',
    '[': ']',
    '(': ')',
  };
  const closer = '}])';

  for (let i = 0; i < str.length; i++) {
    if (str[i] in opener) {
      stack.push(str[i]);
    } else if (closer.includes(str[i])) {
      const top = stack.pop();
      const pair = opener[top];
      if (pair !== str[i]) {
        return false;
      }
    }
  }

  return stack.length === 0;
};
```

 - 해당 문제와는 별개로 다른 괄호와 독립적 탐색하는 로직입니다. 즉, 다른 괄호가 어디에 있든 해당하는 괄호 앞뒤 짝만 맞게 존재하는지 검사하는 로직입니다.

```js
const balancedBrackets = function (str) {
  const temp = str.split('');
  function searchPair(open, close){
    let front = temp.indexOf(open);
    let end = temp.indexOf(close);
    while(front !== -1 || end !== -1) {
      if(front < end && front !== -1 && end !== -1) {
        temp.splice(front, 1);
        temp.splice(end - 1, 1);
        front = temp.indexOf(open);
        end = temp.indexOf(close);
      } else {
        return false;
      }
    }
    return true;
  }
  
  if(searchPair('(',')') && searchPair('{','}') && searchPair('[',']')) {
    return true;
  } else {
    return false;
  }
};
```
