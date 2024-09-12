"use strict";  

window.addEventListener('load', go);

let actions,
  model,
  state,
  view;

function go() {
  console.log('GO !');

  model.init({
    items : [
      { text: 'À faire hier', done: true },
      { text: 'À faire aujourd\'hui', done: false },
      { text: 'À faire demain', done: false }
    ]
  });

  state.samUpdate(model);
}


actions = {

  addItem(data) {
    let text = document.getElementById(data.inputField).value;
    if (text != '') {
      model.samPresent({
        newItem: text
      });
    }
  },

  donneItem(data){
    model.samPresent({donneItem: data.index});
  },

};

model = {
  items: [],

  init(data) {
    this.items = data.items || [];
  },

  samPresent(data) {
    const has = Object.prototype.hasOwnProperty;
  
    if (has.call(data, 'newItem')) {
      let item = {
        text: data.newItem,
        done: false,
      };
  
      this.items.push(item);  
    }
  
    if (has.call(data, 'doneItem')) {
      let index = data.doneItem.index;
      if (this.items[index]) {
        this.items[index].done = true;  
      }
    }
  
    state.samUpdate(this);
  }
  
};

state = {

  samUpdate(model) {
    this.samRepresent(model);

  },

  samRepresent(model) {
    let representation = 'Oops, should not see this...';

    representation = view.normalInterface(model, this);

 
    view.samDisplay(representation);
  }
};

view = {

  samDisplay(representation) {
    const app = document.getElementById('app');
    app.innerHTML = representation;
  },

  normalInterface(model, state) {
    let li_items = this.listItems(model,state);
    return `
      <h2> Todo List </h2>
      <input id="inputText" type="text" />
      <button onclick="actions.addItem( {e: event, inputField:'inputText'} )">Todo</button>
      <ul>
      	${li_items}
      </ul>
      `;
  },

  listItems(model, state) {
    let li_items = model.items.map((v, i) => 
      `<li onclick="actions.doneItem({e:event, index:${i}})">${v.text}</li>`).join(`\n`);
    return li_items;
  }
  
	
};
