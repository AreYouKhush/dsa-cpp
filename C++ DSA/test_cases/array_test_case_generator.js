
function arrayBuilder(n, len, zero) {
  const z = zero ? 0 : 1;
  let s = new Array();
  for (let i = 0; i < n; i++) {
    let num = Math.floor(Math.random() * len + z);
    s.push(num);
  }
  let st = "[";
  s.forEach((e) => {
    st += `${e},`;
  })
  st = st.slice(0, -1);
  st += ']';
  console.log(st);
}

function arrayBuilderUniqueElements(n, len, zero) {
  if(len < n) {
    console.log("Wrong Input");
    return;
  }
  const z = zero ? 0 : 1;
  const s = new Set();
  while (s.size != n) {
    let num = Math.floor(Math.random() * len + z);
    s.add(num);
  }
  let st = "[";
  s.forEach((e) => {
    st += `${e},`;
  })
  st = st.slice(0, -1);
  st += ']';
  console.log(st);
}

arrayBuilder(1000, 10000, false);
// arrayBuilderUniqueElements(100, 100, false);
