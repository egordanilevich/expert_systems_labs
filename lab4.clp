(deffunction ask-question (?question $?allowed-values)
   (printout t ?question)
   (bind ?answer (read))
   (if (lexemep ?answer) 
       then (bind ?answer (lowcase ?answer)))
   (while (not (member ?answer ?allowed-values)) do
      (printout t ?question)
      (bind ?answer (read))
      (if (lexemep ?answer) 
          then (bind ?answer (lowcase ?answer))))
   ?answer)


(deffunction yes-or-no-p (?question)
   (bind ?response (ask-question ?question yes no y n))
   (if (or (eq ?response yes) (eq ?response y))
       then TRUE 
       else FALSE))

(defrule starting-state ""
	(not (start choose ?))
	(not (repair ?))
	=>
	   (if (yes-or-no-p "Can you turn on the computer (yes/no)? ")
       then
	(assert (computer on))  
       else
	(assert (computer off))))

(defrule image ""
	(computer off)
	(not (repair ?))
	=>
		(if (yes-or-no-p "Do you see anything on monitor (yes/no)? ")
		then
	(assert (monitor on))
		else
	(assert (monitor off))))

(defrule computer-stoping ""
	(or(computer on)(monitor on)(video working))
	(not(engine working))
	(not (repair ?))
	=>
		(if (yes-or-no-p "Is computer stopping (yes/no)? ")
		then
	(assert (computer stopping))
		else
	(assert (engine working))))

(defrule monitor-trouble ""
(or(computer on)(monitor on))
(not (repair ?))
=>
(if (yes-or-no-p "Is image on monitor is correct?(yes/no)? ")
		then
	(assert (video working))
		else
	(assert (video not working))))

(defrule computer-stoping-once ""
	(computer stopping)
	(not (repair ?))
	=>
		(if (yes-or-no-p "Is the computer immediately stops(yes/no)? ")
		then
	(assert (cpu/motherboard error))
		else
	(assert (proc temp))))

(defrule cpu-temperature ""
   (proc temp)       
   (not (repair ?))
   =>
   (if (yes-or-no-p "Is the CPU's temperature is rising(yes/no)? ")
		then
	(assert (cpu hot))
		else
	(assert (cpu cold))))


(defrule cpu-overheat ""
	(cpu hot)
	(not (repair ?))
	=>
		(if (yes-or-no-p "Is CPU overheats?(yes/no)? ")
		then
	(assert (cpu overheat))
		else
	(assert (pu error))))

(defrule fun-error ""
(cpu overheat)
(not (repair ?))
    =>
    (assert (repair "Check connection and/or cooling")))

(defrule monitor-error ""
(monitor off)
(not (repair ?))
=>
(assert (repair "Check monitor connection")))

(defrule video-error ""
(video not working)
(not (repair?))
=>
(assert (repair "Check the GPU or get certified help")))

(defrule cp/mat-error ""
(cpu/motherboard error)
(not (repair ?))
=>
(assert (repair "CPU or motherboard issue, get certified help")))

(defrule pu-error ""
(pu error)
(not (repair ?))
=>
(assert(repair "Power supply unit issue, get certified help")))

(defrule all-good ""
(computer on)
(video working)
(engine working)
=> (assert(repair "Everything works fine")))

(defrule print-repair ""
(declare (salience 10))
(repair ?item)
=>
(printout t crlf crlf)
(format t " %s%n%n%n" ?item))







