(define (range n)
  (if (zero? n) '() (cons (- n 1) (range( - n 1)))))


(define (carre n)
  (if (zero? n) '() (let ((x (- n 1))) (cons (* x x) (carre (- n 1))))))


 (define (p2* k n)
  (if (zero? n) '() (cons k (p2* (* 2 k) (- n 1)))))

 (define (p2 n) (p2* 1 n))


 (define (binaire n)(if (< n 2) (cons n '())(cons (modulo n 2) (binaire (quotient n 2)))))