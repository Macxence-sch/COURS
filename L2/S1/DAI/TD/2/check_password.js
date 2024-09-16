

function checkPassword() {
  const pw     = document.getElementById('passwd').value;
  const resElt = document.getElementById('result');

  const c1 = checkLength(pw,8,10);
  const c2 = checkAllowedChars(pw); 
  const c3 = checkMinChars2(pw); 
  const c4 = checkMinChars(pw); 
  const c5 = checknumber(pw); 
  const isValid = c1 && c2 && c3 && c4 && c5;
  
  const validText = isValid ? 'valide !' : 'invalide...';

  const cvalid   = 'class="valid"'
  const cinvalid = 'class="invalid"'
  const ch1 = c1 ? cvalid : cinvalid;
  const ch2 = c2 ? cvalid : cinvalid;
  const ch3 = c3 ? cvalid : cinvalid;
  const ch4 = c4 ? cvalid : cinvalid;
  const ch5 = c5 ? cvalid : cinvalid;
 
  const html = `
  <style>
    .valid   { color:green; }
    .invalid { color:red;   }
  </style>
  <p>Votre mot de passe doit contenir :</p>
  <ul>
    <li ${ch1}>entre 8 et 10 caractères</li>
    <li ${ch2}>que des lettres et des chiffres</li>
    <li ${ch3}>au moins 2 minuscules</li>
    <li ${ch4}>au moins 1 majuscules</li>
    <li ${ch5}>au moins 2 chiffres</li>
  </ul>
  <p>Le mot de passe est ${validText}</p>
  `;

  resElt.innerHTML = html;
}
