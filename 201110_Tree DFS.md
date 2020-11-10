Q
 - Tree DFS 탐색하여 탐색 순으로 값을 반환하시오. (배열 타입으로)

 - 깊이에 따른 필터링이 가능해야 합니다.



A
 - dfs 파라미터로 result 배열을 넣어주는 형태입니다. 재귀를 활용했지만 다소 원초적인 방법이라 생각이 듭니다.
```js
let dfs = function (node, result) {
  if(result === undefined) {
    result = [];
  }
  result.push(node.value);
  if(node.children.length !== 0) {
    for(let i = 0; i < node.children.length; i++) {
      dfs(node.children[i], result);
    }
  }
  return result;
};

let Node = function (value) {
  this.value = value;
  this.children = [];
};

Node.prototype.addChild = function (child) {
  this.children.push(child);
  return child;
};
```

 - 그렇기에 children 배열을 순회하면서 각 값들을 인자로 하여 dfs를 재귀호출하고, dfs 재귀호출 값을 result 배열의 요소로 concat 해버리면 보다 직관적으로 코딩할 수 있습니다.
```js
let dfs = function (node) {
  let values = [node.value];

  node.children.forEach((n) => {
    values = values.concat(dfs(n));
  });

  return values;
};
```
