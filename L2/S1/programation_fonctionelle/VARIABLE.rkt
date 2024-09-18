(let (( x 5))

(* x x))

(define (g x)
  (* 2 (* x x)))

(define (h x)
  (let ((x2 (* x x)))
    (if (< x2 50) (+ x2 1) (- x2 1))))


(define (power2 k)
  (if (zero? k) '(1)
      (let ((p (power2 (- k 1))))
        (cons (* 2 (car p)) p))))

(define (fibo n)
  (cond
    ((zero? n) '(0))
    ((= 1 n) '(1 0))
    (else
     (let ((f (fibo (- n 1))))
       (cons (+ (car f) (cadr f)) f)))))

;cadr est l'abréviation de (car (cdr f))
;cdar (cdr (car l))
;cdadr (cdr (car (cdr l)))
;caddr est l'abréviation de (car (cdr (cdr f))