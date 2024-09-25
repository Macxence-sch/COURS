(define l '( 1 2 3 3 4 4 4 4 5 5 5 6 ))
(define i '(1 0 0 1 1 0 1))

; Compter les occurences

(define (count l e)
  (if (null? l) 0
      (if (= e (car l)) (+ 1 (count (cdr l) e))
          (count (cdr l) e))))

(define (count2 l e)
  (cond
    ((null? l) 0)
    ((= e (car l)) (+ 1 (count2 (cdr l) e)))
    (else 
     (count2 (cdr l) e))))

(define (count3 l e)
    (if (null? l) 0
      (let ((c (count3 (cdr l) e)))
        (if (= e (car l)) (+ 1 c) c))))


;accéder au K-ieme element d'une liste

(define (mynth l k)
  (if (zero? k) (car l)
      (mynth (cdr l) (- k 1))))


;Verifier que tous les elements sont non NULL

(define (nnull? l)
  (if (null? l) #t
      (if (zero? (car l)) #f
          (nnull? (cdr l)))))

;Passer d'un nmbre Binare a un nombre en classe 10

(define i '(1 0 1 1))

(define (conv-aux i p)
  (if (null? i) 0
     (+ (if (zero? (car i)) 0 p)
        (conv-aux (cdr l) (* 2 p)))))

(define (conv i) (conv-aux i 1))


;Valider un nombre binaire 

(define (validb i)
  (cond
    ((null? i) #f)
    ((and (null? (cdr i)) (= (car i) 1)) #t)
     (else
      (and
       ; premiere condition : 
       (or (zero? (car i)) (= 1 (car i)))
       ; deuxieme condition :
       ; La suite du "nombre" est elle meme valide
       (validb (cdr i))))))


;Renvoyer la liste des ocurants

(define (indicocc-aux l e k)
  (if (null? l) '()
      (if (= e (car l)) (cons k (indicocc-aux (cdr l) e (+ k 1)))
          (indicocc-aux (cdr l) e (+ k 1)))))
          


(define (indicocc l e)
  (indicocc-aux l e 0))