"use strict";  // le mode strict impose une version plus exigente de Javascript

// Demande le lancement de l'exécution quand toute la page Web sera chargée
window.addEventListener('load', go);

// SAM Design Pattern : http://sam.js.org/
let actions, model, state, view;

// Point d'entrée de l'application
function go() {
  console.log('GO !');

  // Initialise le modèle avec la liste de départements et un mode d'affichage
  model.init({
    // items: ['1ère chose à faire', '2ème truc important', '...'],
    items: [{ text: 'À faire hier', done: false },
    { text: 'À faire aujourd\'hui', done: false },
    { text: 'À faire demain', done: false },],
  });

  // Appelle l'affichage de l'application.
  state.samUpdate(model);
}

//------------------------------------------------------------------ Actions ---
// Actions appelées dans le code HTML quand des événements surviennent
//
actions = {

  // Demande au modèle d'ajouter un item à son tableau de tâches à faire.
  // Lui envoit pour cela un objet avec une propriété 'inputField' qui
  // désigne l'id de l'élément qui contient le texte à ajouter.
  addItem(data) {
    let text = document.getElementById(data.inputField).value;
    if (text != '') {
      model.samPresent({
        newItem: text
      });
    }
  },
  doneItem(data) {
    model.samPresent({ doneItem: data.index });
  }

  removeDoneItems() {
    model.samPresent({doneItem:'removeDoneItems'});
  };

};
//-------------------------------------------------------------------- Model ---
// Unique source de vérité de l'application
//
model = {
  items: [],
  isEditMode: false,

  init(data) {
    this.items = data.items || [];
  },

  // Demande au modèle de se mettre à jour en fonction des données qu'on
  // lui présente.
  // l'argument data est un objet confectionné dans les actions.
  // Les propriétés de data désignent la modification à faire sur le modèle.
  samPresent(data) {
    const has = Object.prototype.hasOwnProperty; // test si la propriété
    // d'un objet est présente

    // Si l'objet data possède la propriété 'newItem'
    // alors on ajoute ce nouvel item au tableau de tâches de model.
    if (has.call(data, 'newItem')) {
      let item = {
        text: data.newItem,
        done: false,
      };
      this.items.push(item);
    }
    if (has.call(data, 'doneItem')) {
      let index = data.doneItem;
      this.items[index].done = !this.items[index].done;
      console.log(index + ' : ' + this.items[index].done);
      
      .
    }

    // Demande à l'état de l'application de prendre en compte la modification
    // du modèle
    state.samUpdate(this);
  }
};
//-------------------------------------------------------------------- State ---
// État de l'application avant affichage
//
state = {

  samUpdate(model) {
    this.samRepresent(model);
    // this.samNap(model);
  },

  // Met à jour l'état de l'application, construit le code HTML correspondant,
  // et demande son affichage.
  samRepresent(model) {
    let representation = 'Oops, should not see this...';

    representation = view.normalInterface(model, this);

    // Appel l'affichage du HTML généré.
    view.samDisplay(representation);
  }
};
//--------------------------------------------------------------------- View ---
// Génération de portions en HTML et affichage
//
view = {

  // Injecte le HTML dans une balise de la page Web.
  samDisplay(representation) {
    const app = document.getElementById('app');
    app.innerHTML = representation;
  },

  // Renvoit le HTML
  normalInterface(model, state) {
    let li_items = model.isEditMode ? this.editItems(model, state)
      : this.listItems(model, state);
    return `
      <style type="text/css">
      .done {
        text-decoration: line-through;
      }
      ul>li {
        line-height: 4.5ex;
        padding-left: 0.5ex;
      }
      ul>li>input {
        margin-left: -0.5ex;
      }
      </style>
      <h2> Todo List </h2>
      <input id="inputText" type="text" />
      <button onclick="actions.addItem( {inputField:'inputText'} )">Todo</button>
      <ul>
      	${li_items}
      </ul>
      `;
  },

  listItems(model, state) {
    let li_items = model.items.map((v, i) =>
      `<li onclick="actions.doneItem({index:${i}})" ${v.done ? 'class="done"' : ''}>${v.text}</li>`).join('\n');
    return li_items;
  }
};
