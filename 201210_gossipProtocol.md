Q
 - 세로와 가로의 길이가 각각 M, N인 마을지도가 배열로 주어졌을 때, '1'은 주민이 있는 집을 의미하고 '0'은 주민이 없는 땅을 의미합니다. 이 마을은 소문이 시작되면 하루에 상하좌우 한 칸 바로 옆에 있는 집으로 소문이 퍼집니다. 특정 주민의 집 (R, C)으로부터 어떤 소문이 시작될 경우, 마을 전체로 소문이 퍼지는데 걸리는 시간(일)을 리턴해야 합니다.

 - row, col에는 항상 주민이 살고 있으며, 모든 집은 연결되어 있습니다. 즉, 한 집에서 다른 집으로 가는 경로가 항상 존재합니다

 

A
 - 전형적인 큐를 활용한 bfs 알고리즘 문제입니다. 현재 지점에서 갈 수 있는 집(자식 노드)을 enQueue하고, 작업 처리 후 deQueue하는 형식입니다. 이때, 현재 자식노드들의 매트릭스 값을 현재 노드 기준에 +1을 하는 방식으로 노드 레벨을 카운트할 수 있습니다. 정리를 하자면 큐와 bfs를 활용하여 자식 노드를 탐색하고, 해당 level을 카운트 하는 방식을 통하여 총 시간(일)을 구할 수 있습니다.

 - 이때, enQueue, deQueue 시마다 리 인덱싱 하지 않고, 메모리를 절약하려면 순환 큐 형식으로 구현하면 됩니다. 그렇기에 queue의 크기를 매트리스 최대 크기만큼 선언하고 로직을 시작합니다. (이때, 큐에는 좌표값이 들어가며, 문제 특성상 한번 지나간 좌표는 다시 지나가지 않습니다.)

```js
const createMatrix = (village) => {
  const matrix = [];
  village.forEach((line) => {
    const row = [];
    for (let i = 0; i < line.length; i++) row.push(line[i]);
    matrix.push(row);
  });
  return matrix;
};

const gossipProtocol = function (village, row, col) {
  // bfs 구현을 위해 큐를 선언한다.
  // 저장공간을 아끼고, enQueue, deQueue시마다 인덱싱을 다시 하지 않기 위해
  // 순환 큐(circular queue)로 구현한다.
  // queue의 가능한 최대 크기만큼 배열을 선언한다.
  // 문제의 특성에 따라 큐에는 좌표 평면의 한 점이 삽입되고, 한번 삽입된 요소는 두 번 다시 삽입되지 않는다.
  const R = village.length;
  const C = village[0].length;
  const matrix = createMatrix(village);
  const MOVES = [
    [-1, 0], // UP
    [1, 0], // DOWN
    [0, 1], // RIGHT
    [0, -1], // LEFT
  ];
  const MAX_SIZE = R * C; // 가능한 모든 좌표의 크기만큼 큐가 선언되었으므로, 사실 순환큐일 필요는 없다.
  const isValid = (row, col) => row >= 0 && row < R && col >= 0 && col < C;
  const queue = Array(MAX_SIZE);
  let front = 0;
  let rear = 0;
  const isEmpty = (queue) => front === rear;
  const enQueue = (queue, pos) => {
    // 실행 중에 큐의 크기를 넘는 요소가 삽입되지 않는다고 가정하기 때문에
    // 별도의 조건문을 작성하지 않는다.
    queue[rear] = pos;
    rear = (rear + 1) % MAX_SIZE;
  };
  const deQueue = (queue) => {
    const pos = queue[front];
    front = (front + 1) % MAX_SIZE;
    return pos;
  };

  let cnt = 0;
  enQueue(queue, [row, col]);
  // 소문이 퍼지는 데 걸리는 시간을 저장한다.
  matrix[row][col] = 0;
  while (isEmpty(queue) === false) {
    // 큐의 가장 앞 자리의 좌표를 얻는다.
    const [row, col] = deQueue(queue);
    if (matrix[row][col] > cnt) cnt = matrix[row][col];

    // 현재 지점을 기준으로 네 방향을 검토한다.
    MOVES.forEach((move) => {
      const [rDiff, cDiff] = move;
      const nextRow = row + rDiff;
      const nextCol = col + cDiff;
      if (isValid(nextRow, nextCol) && matrix[nextRow][nextCol] === '1') {
        enQueue(queue, [nextRow, nextCol]);
        matrix[nextRow][nextCol] = matrix[row][col] + 1;
      }
    });
  }
  return cnt;
};
```
