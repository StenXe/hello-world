(defvar A ) 
(defvar B ) 
(defvar C ) 
(defvar D )


(defun :bits (value)
  (format t "~64,'0b~%" value))

(write-line "Welcome To Calculator") 


(write-line "Enter A: ") 
(setq A (read)) 
(:bits A)

(terpri)
(write-line "Enter B: ") 
(setq B (read)) 
(:bits B)

(terpri)

 
(write-line "1.Addition") 
(write-line "2.Subtraction") 
(write-line "3.Multiplication") 
(write-line "4.Division") 
(write-line "5.AND")
(write-line "6.OR")
(write-line "7.NOT")
 
(sb-thread:make-thread (lambda () (progn (sleep 0)
(setq C (+ A B)) 
(write-line "Addition Of Two Numbers: ") 
(:bits C))))


(sb-thread:make-thread (lambda () (progn (sleep 2)
(setq C (- A B)) 
(write-line "Subtraction Of Two Numbers: ") 
(:bits C))))

	 
(sb-thread:make-thread (lambda () (progn (sleep 4)
(setq C (* A B)) 
(write-line "Multiplication Of Two Numbers: ")
(:bits C))))

(sb-thread:make-thread (lambda () (progn (sleep 6)
(setq C (/ A B)) 
(write-line "Division Of Two Numbers: ")
(:bits C))))

(sb-thread:make-thread (lambda () (progn (sleep 8)
(setq C (logand A B)) 
(write-line "AND Operation Of Two Numbers: ") 
(:bits C))))

(sb-thread:make-thread (lambda () (progn (sleep 10)
(setq C (logior A B)) 
(write-line "OR Operation Of Two Numbers: ")
(:bits C))))

(sb-thread:make-thread (lambda () (progn (sleep 12)
(setq C (lognot A )) 
(write-line "NOT Operation Of First Number: ") 
(:bits C))))
 
(sb-thread:make-thread (lambda () (progn (sleep 14)
(setq C (lognot B)) 
(write-line "NOT Operation Of Second Number: ")
(:bits C)))) 
 
 
(terpri)
(sb-thread:make-thread (lambda () (progn (sleep 16)
(write-line "Do you want to continue?Y-2/N-1")
(setq D (read))
(if (= D 1)
(exit)))))


