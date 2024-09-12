"use strict";

window.addEventListener('load', go);

let actions,
  model,
  state,
  view;

function go() {
  console.log('GO !');

  model.init({
    items: [
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
    if (text !== '') {
      model.samPresent({
        newItem: text
      });
    }
  },

  doneItem(data) {
    model.samPresent({ doneItem: data.index });
  }

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
      let index = data.doneItem;
      if (this.items[index]) {
        // Inverser l'état 'done'
        this.items[index].done = !this.items[index].done;
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
    let representation = view.normalInterface(model, this);
    view.samDisplay(representation);
  }
};

view = {

  samDisplay(representation) {
    const app = document.getElementById('app');
    app.innerHTML = representation;
  },

  normalInterface(model, state) {
    let li_items = this.listItems(model, state);
    return `
      <h2> Todo List </h2>
      <input id="inputText" type="text" />
      <button onclick="actions.addItem( {e: event, inputField:'inputText'} )">Ajouter</button>
      <ul>
        ${li_items}
      </ul>
      `;
  },

  listItems(model, state) {
    let li_items = model.items.map((v, i) => 
      `<li class="${v.done ? 'done' : ''}" onclick="actions.doneItem({e: event, index: ${i}})">${v.text}</li>`
    ).join('\n');
    return li_items;
  }
  
};

// Ajout du style CSS pour barrer les items terminés
const style = document.createElement('style');
style.innerHTML = `
  .done {
    text-decoration: line-through;
    color: gray;
  }
`;
document.head.appendChild(style);
