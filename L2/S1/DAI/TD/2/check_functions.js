//--- Vérification de la nature des caractères

function isNumber(c) {
  return !isNaN(c * 1); // cadeau !  isNaN == is Not a Number (inclus dans Javascrit)
}                       // On tente la conversion de caractère en nombre avec * 1

function isLetter(c) {  // la majuscule est différente de sa minuscule... toUpperCase(), toLowerCase
  return /^[a-zA-Z]$/.test(c);
}

function isLetterOrNumber(c) {
  if (!(isNumber(c) || isLetter(c))){
    return false;
  }
  return true; 
}

function isLowerCaseLetter(c) {
  return /^[a-z]$/.test(c)

}
d
function isUpperCaseLetter(c) {
  return /^[A-Z]$/.test(c);
}

// Vérifie si la longueur de str est dans [lenMin, lenMax]
function checkLength(str, lenMin, lenMax) {
  return str.length >= lenMin && str.length <= lenMax; // TODO
}

//--- Vérification de la conformité des chaînes de caractères

// Vérifie s'il n'y a que des caractères autorisés (lettres et chiffres)

function checkAllowedChars(str) {
  for (let i=0; i<str.length; i = i + 1){
    if (!isLetterOrNumber(str[i])){
      return false;
    }
  }
  return true;
}

// Vérifie si str contient au moins min caractères autorisés par isCharFunc
// exemple d'appel :
//    checkMinChars('ab12+-', 2, isLowerCaseLetter) vérifie si 'ab12+-' contient
//                                                  au moins deux minuscules :
//                                                  Renvoie 'true'.
function checkMinChars(str, min = 1, isCharFunc = isLetterOrNumber) {
  let j = 0;
  for (let i=0; i<str.length; i = i + 1){
    if (isUpperCaseLetter(str[i])){
      j=j+1;}
    }
  if(j>=1){
    return true;
  }
  
  return false; // TODO
}

function checkMinChars2(str, min = 1, isCharFunc = isLetterOrNumber) {
  let j = 0;
  for (let i=0; i<str.length; i = i + 1){
    if (isLowerCaseLetter(str[i])){
      j=j+1;}
    }
  if(j>=2){
    return true;
  }
  
  return false; // TODO
}

function checknumber(str, min = 1, isCharFunc = isLetterOrNumber) {
  let j = 0;
  for (let i=0; i<str.length; i = i + 1){
    if (isNumber(str[i])){
      j=j+1;}
    }
  if(j>=2){
    return true;
  }
  
  return false; // TODO
}



//--- Tests ---
// Tous doivent afficher '+ Passed' !
// utilisation : test(résultatAttendu, functionÀTester, arg1, ..., argN)

const faireTests = true;

if (faireTests) {

  let ft = 0;  // failed tests - nombre de tests ratés

  console.log('=== Test des fonctions ===');

  console.log('--- est un nombre ---');
  ft += ! test(true,  isNumber, '1'); // Attentdu : isNumber('1') == true
  ft += ! test(false, isNumber, 'a'); // Attentdu : isNumber('a') == false

  console.log('--- est une minuscule ---');
  ft += ! test(true,  isLowerCaseLetter, 'a');
  ft += ! test(false, isLowerCaseLetter, 'A');

  console.log('--- est une majuscule ---');
  ft += ! test(true,  isUpperCaseLetter, 'A');
  ft += ! test(false, isUpperCaseLetter, 'a');

  console.log('--- est une lettre ---');
  ft += ! test(true,  isLetter, 'a');
  ft += ! test(false, isLetter, '1');

  console.log('--- Entre 8 et 10 caractères ---');
  ft += ! test(true,  checkLength, '12345678', 8, 10);
  ft += ! test(false, checkLength, '1234567', 8, 10);
  ft += ! test(false, checkLength, '12345678901', 8, 10);

  console.log('--- Seulement composé de lettres et de chiffres ---');
  ft += ! test(true,  checkAllowedChars, 'abcABC123'); //
  ft += ! test(false, checkAllowedChars, 'abcABC12+');

  console.log('--- Au moins 1 majuscule ---');
  ft += ! test(true,  checkMinChars, 'aB12+-', 1, isUpperCaseLetter);
  ft += ! test(false, checkMinChars, 'ab12+-', 1, isUpperCaseLetter);

  console.log('--- Au moins 2 minuscules ---');
  ft += ! test(true,  checkMinChars, 'ab12+-', 2, isLowerCaseLetter);
  ft += ! test(false, checkMinChars, 'aB12+-', 2, isLowerCaseLetter);

  console.log('--- Au moins 2 chiffres ---');
  ft += ! test(true,  checkMinChars, 'aB123+-', 2, isNumber);
  ft += ! test(false, checkMinChars, 'abcd3+-', 2, isNumber);

  console.log(`=== ${ft} test(s) raté(s) ! ===`);
}

// Fonction de test
// (ne pas toucher...)
function test() {
  let [result, func, ...args] = arguments;
  let res = func(...args) === result
  let passedFailed = res ? '+ Passed' : '- Failed';
  let sign         = res ?    '==='   :    '!==';
  let message = `${passedFailed}: ${func.name}(${args.map(v => v.name || v)
                .join(', ')}) ${sign} ${result}`;
  if (res) {console.log(message);} else {console.error(message);}
  return res;
}
