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

(defrule determine-virus-state ""
   (not (virus-state virus ?))
   (not (repair ?))
   =>
   (if (yes-or-no-p " Do you think your computer is infected with viruses (yes/no)? ")
   then
      (assert (virus-state virus yes))
   else
      (assert (virus-state virus no))))

(defrule determine-screamer-state ""
   (virus-state virus yes)
   (not (screamer-state screamer ?))
   (not (repair ?))
   =>
   (if (yes-or-no-p " Do unexpected sounds, messages or images appear on the computer (yes/no)? ")
   then
      (assert (screamer-state screamer yes))
   else
      (assert (screamer-state screamer no))))

(defrule determine-initiative-state ""
   (or (screamer-state screamer yes)(screamer-state screamer no))
   (not (initiative-state initiative ?))
   (not (repair ?))
   =>
   (if (yes-or-no-p " Do the programs run independently or connect to the Internet (yes/no)? ")
   then
      (assert (initiative-state initiative yes))
   else
      (assert (initiative-state initiative no))))

(defrule determine-email-state ""
   (or (initiative-state initiative yes)(initiative-state initiative no))
   (not (email-state email ?))
   (not (repair ?))
   =>
   (if (yes-or-no-p " Do your friends receive messages via email or messenger that you didn't send (yes/no)? ")
   then
      (assert (email-state email yes))
   else
      (assert (email-state email no))))

(defrule determine-spam-state ""
   (or (email-state email yes)(email-state email no))
   (not (spam-state spam ?))
   (not (repair ?))
   =>
   (if (yes-or-no-p " Are there a lot of messages in your mailbox without the sender's address and the subject of the letter (yes/no)? ")
   then
      (assert (spam-state spam yes))
   else
      (assert (spam-state spam no))))

(defrule determine-snail-state ""
   (or (spam-state spam yes)(spam-state spam no))
   (not (snail-state snail ?))
   (not (repair ?))
   =>
   (if (yes-or-no-p " Is the computer running slowly or freezes frequently (yes/no)? ")
   then
      (assert (snail-state snail yes))
   else
      (assert (snail-state snail no))))

(defrule determine-os-state ""
   (or (snail-state snail yes)(snail-state snail no))
   (not (os-state os ?))
   (not (repair ?))
   =>
   (if (yes-or-no-p " When you turn on the computer, the operating system does not boot (yes/no)? ")
   then
      (assert (os-state os yes))
   else
      (assert (os-state os no))))

(defrule determine-disappear-state ""
   (or (os-state os yes)(os-state os no))
   (not (disappear-state disappear ?))
   (not (repair ?))
   =>
   (if (yes-or-no-p " Files and folders disappear or their contents change (yes/no)? ")
   then
      (assert (disappear-state disappear yes))
   else
      (assert (disappear-state disappear no))))

(defrule determine-message-state ""
   (or (disappear-state disappear yes)(disappear-state disappear no))
   (not (message-state message ?))
   (not (repair ?))
   =>
   (if (yes-or-no-p " Does a lot of system error messages pop up (yes/no)? ")
   then
      (assert (message-state message yes))
   else
      (assert (message-state message no))))

(defrule determine-browser-state ""
   (or (message-state message yes)(message-state message no))
   (not (browser-state browser ?))
   (not (repair ?))
   =>
   (if (yes-or-no-p " The browser freezes and behaves in an unexpected way (yes/no)? ")
   then
      (assert (browser-state browser yes))
   else
      (assert (browser-state browser no))))

(defrule virus-companion ""
   (and (screamer-state screamer no)
   (initiative-state initiative no)
   (email-state email no)
   (spam-state spam no)
   (snail-state snail yes)
   (os-state os no)
   (disappear-state disappear no)
   (message-state message no)
   (browser-state browser no))
   (not (repair ?))
   =>
   (assert (repair "Your virus is 'virus-companion'")))

(defrule virus-warm ""
   (and (screamer-state screamer no)
   (initiative-state initiative yes)
   (email-state email no)
   (spam-state spam no)
   (snail-state snail yes)
   (os-state os no)
   (disappear-state disappear no)
   (message-state message no)
   (browser-state browser no))
   (not (repair ?))
   =>
   (assert (repair "Your virus is 'virus-warm'")))

(defrule virus-parasite ""
   (and (screamer-state screamer no)
   (initiative-state initiative no)
   (email-state email no)
   (spam-state spam no)
   (snail-state snail yes)
   (os-state os no)
   (disappear-state disappear yes)
   (message-state message no)
   (browser-state browser no))
   (not (repair ?))
   =>
   (assert (repair "Your virus is 'virus-parasite'")))

(defrule virus-stealth ""
   (and (screamer-state screamer no)
   (initiative-state initiative no)
   (email-state email no)
   (spam-state spam no)
   (snail-state snail yes)
   (os-state os no)
   (disappear-state disappear yes)
   (message-state message no)
   (browser-state browser yes))
   (not (repair ?))
   =>
   (assert (repair "Your virus is 'virus-stealth'")))

(defrule virus-trojans ""
   (and (screamer-state screamer no)
   (initiative-state initiative yes)
   (email-state email yes)
   (spam-state spam yes)
   (snail-state snail yes)
   (os-state os yes)
   (disappear-state disappear yes)
   (message-state message no)
   (browser-state browser no))
   (not (repair ?))
   =>
   (assert (repair "Your virus is 'virus-trojans'")))

(defrule virus-adware ""
   (and (screamer-state screamer yes)
   (initiative-state initiative yes)
   (email-state email no)
   (spam-state spam yes)
   (snail-state snail no)
   (os-state os no)
   (disappear-state disappear no)
   (message-state message no)
   (browser-state browser yes))
   (not (repair ?))
   =>
   (assert (repair "Your virus is 'virus-adware'")))

(defrule virus-jokes ""
   (and (virus-state virus yes)(screamer-state screamer yes)
   (initiative-state initiative no)
   (email-state email no)
   (spam-state spam no)
   (snail-state snail no)
   (os-state os no)
   (disappear-state disappear no)
   (message-state message yes)
   (browser-state browser no))
   (not (repair ?))
   =>
   (assert (repair "Your virus is virus-jokes")))

(defrule no-repairs ""
   (declare (salience -10))
   (not (repair ?))
   =>
   (printout t crlf crlf)
   (printout t " Contact the service center.")
   (printout t crlf crlf))

(defrule print-repair ""
   (declare (salience 10))
   (repair ?item)
   =>
   (printout t crlf crlf)
   (printout t "Recommendations for repair:")
   (printout t crlf crlf)
   (format t " %s%n%n%n" ?item)
)
