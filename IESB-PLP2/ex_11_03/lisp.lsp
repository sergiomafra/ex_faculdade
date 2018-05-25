
(defun mod (a b)
   (- a (* b (FLOOR (/ a b))))
)

(defun den (n)
   (/ 4 (- (* n 2) 1))
)

(defun num (n)
   (if (zerop (mod n 2))
          (* -1 (den n))
                (den n))
)

(defun pi (n)
 (if (<= n 0)
   0
   (+ (num n) (pi (- n 1))))
)

(pi 5)