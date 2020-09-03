type last('a, 'b) = {
  params: 'a,
  res: 'b,
};

let diffInLength = (x, y) => Array.length(x) != Array.length(y);

let diffInElement = (x, y) => {
  let i = ref(0);
  let n = Array.length(x);
  let diff = ref(false);

  while (! diff^ && i^ < n) {
    if (x[i^] != y[i^]) {
      diff := true;
    };
    i := i^ + 1;
  };

  diff^;
};

let isEmpty = x => Array.length(x) == 0;

let memoize = fn => {
  let last = ref(None);
  params => {
    switch (last.contents) {
    | None =>
      let newRes = fn(params);
      let newLast = {params, res: newRes};
      last := Some(newLast);
      newRes;
    | Some(contents) =>
      if (!isEmpty(params) && (diffInLength(contents.params, params) || diffInElement(contents.params, params))) {
        let newRes = fn(params);
        let newLast = {params, res: newRes};
        last := Some(newLast);
        newRes;
      } else {
        contents.res;
      }
    };
  };
};

let memoize0 = fn => {
  let fn0 = _ => fn();
  let memoized = memoize(fn0);
  () => memoized([||])
};

let memoize1 = fn => {
  let fn1 = x => fn(x[0]);
  let memoized = memoize(fn1);
  x => memoized([|x|])
};

let memoize2 = fn => {
  let fn2 = x => fn(x[0], x[1]);
  let memoized = memoize(fn2);
  (x, y) => memoized([|x, y|])
};

let memoize3 = fn => {
  let fn3 = x => fn(x[0], x[1], x[2]);
  let memoized = memoize(fn3);
  (x, y, z) => memoized([|x, y, z|])
};

let memoize4 = fn => {
  let fn4 = x => fn(x[0], x[1], x[2], x[3]);
  let memoized = memoize(fn4);
  (x, y, z, a) => memoized([|x, y, z, a|])
};
