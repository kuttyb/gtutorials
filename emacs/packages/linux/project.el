;; =====================================
;; Project Management
;; =====================================
( setenv "WORKBASE" "/Users/kutty_banerjee/daji/code" )
( set 'CURRENTPROJECT 0 )


( defun unloadTags ()
 ( set 'tags-file-name  nil )
 ( set 'tags-table-list nil )
  )

( defun loadTags ()
  ( let ( ( branchDir ) )
    ( set 'tags-table-list 
          ( list ( concat ( getenv "WORKROOT" ) "/.tags" ) ) 
          )
    )
  )

( defun setFrameTitle () 
  ( set 'newFrameTitle ( concat "==============================================" newFrameTitle "==============================================" ) )
  ( set 'frame-title-format newFrameTitle )
  )

;; Kill all current buffers except eshell
( defun killBuffers ( )
  " Kills all buffers except eshell in the current emacs frame"
  ( let* ( ( counter        0 ) 
           ( currentBuffers ( buffer-list ) ) 
           ( maxBuffers     ( length currentBuffers ) )
           ( tempBuffer ) )
    
    ;; iterate over all buffers
    ( while ( < counter maxBuffers ) 
      ( set 'tempBuffer ( elt currentBuffers counter ) )
      ( message "Dealing with buffer %s" ( buffer-name tempBuffer ) )
      ( if ( and ( not ( equal ( buffer-name tempBuffer ) "*eshell*"        ) )
                 ( not ( equal ( buffer-name tempBuffer ) "*hwcompilation*" ) )
                 ( not ( equal ( buffer-name tempBuffer ) "*Messages*"      ) )
                 ( not ( equal ( buffer-name tempBuffer ) "*grep*"          ) )
                 ( not ( equal ( buffer-name tempBuffer ) "*kbanerjee-output*"  ) )
                 ( not ( equal ( buffer-name tempBuffer ) "*compilation*"   ) ) )
          ( progn 
            ( message "About to kill buffer %s" ( buffer-name tempBuffer ) )
            ( kill-buffer tempBuffer ) )
        )
      ( set 'counter ( + counter 1 ) )
      )
    )
  )


( defun _loadProject ( clientNum )
  ( cond
    ( ( eq clientNum 1 ) 
      ( setenv "WORKROOT" ( concat ( getenv "WORKBASE" ) "/work" ) )
      ( set 'newFrameTitle "Work-1")   ( setFrameTitle )
      ( set 'CURRENTPROJECT clientNum )
      ( unloadTags) ( loadTags )
      ( setenv "CURR_DSTROOT" ( concat ( getenv "WORKROOT" ) "/_out" ) ) 
      )

    ( ( eq clientNum 2 ) 
      ( setenv "WORKROOT" ( concat ( getenv "WORKBASE" ) "/work2" ) )
      ( set 'newFrameTitle "Work-2")   ( setFrameTitle )
      ( set 'CURRENTPROJECT clientNum )
      ( unloadTags) ( loadTags )
      ( setenv "CURR_DSTROOT" ( concat ( getenv "WORKROOT" ) "/_out" ) ) 
      )

    ( ( eq clientNum 3 ) 
      ( setenv "WORKROOT" ( concat ( getenv "WORKBASE" ) "/work3" ) )
      ( set 'newFrameTitle "Work-3")   ( setFrameTitle )
      ( set 'CURRENTPROJECT clientNum )
      ( unloadTags) ( loadTags )
      ( setenv "CURR_DSTROOT" ( concat ( getenv "WORKROOT" ) "/_out" ) ) 
      )

    ( ( eq clientNum 4 ) 
      ( setenv "WORKROOT" ( concat ( getenv "WORKBASE" ) "/work4" ) )
      ( set 'newFrameTitle "Work-4")   ( setFrameTitle )
      ( set 'CURRENTPROJECT clientNum )
      ( unloadTags) ( loadTags )
      ( setenv "CURR_DSTROOT" ( concat ( getenv "WORKROOT" ) "/_out" ) ) 
      )

    ( ( eq clientNum 5 ) 
      ( setenv "WORKROOT" ( concat ( getenv "WORKBASE" ) "/work5" ) )
      ( set 'newFrameTitle "Work-5")   ( setFrameTitle )
      ( set 'CURRENTPROJECT clientNum )
      ( unloadTags) ( loadTags )
      ( setenv "CURR_DSTROOT" ( concat ( getenv "WORKROOT" ) "/_out" ) ) 
      )


    ( ( eq clientNum 6 ) 
      ( setenv "WORKROOT" ( concat ( getenv "WORKBASE" ) "/work6" ) )
      ( set 'newFrameTitle "Work-6")   ( setFrameTitle )
      ( set 'CURRENTPROJECT clientNum )
      ( unloadTags) ( loadTags )
      ( setenv "CURR_DSTROOT" ( concat ( getenv "WORKROOT" ) "/_out" ) ) 
      )


    ( ( eq clientNum 7 ) 
      ( setenv "WORKROOT" ( concat ( getenv "WORKBASE" ) "/work7" ) )
      ( set 'newFrameTitle "Work-7")   ( setFrameTitle )
      ( set 'CURRENTPROJECT clientNum )
      ( unloadTags) ( loadTags )
      ( setenv "CURR_DSTROOT" ( concat ( getenv "WORKROOT" ) "/_out" ) ) 
      )
    
    ( t                  ( message "incorrect workspace client id ") )
    )
  )


( defun loadProject ( clientNum )
  (unloadTags)

  (_loadProject clientNum)

  ( killBuffers )
  )


;; -------------------
;; GNU Global
;; -------------------
(defun gtags-root-dir ()
  "Returns GTAGS root directory or nil if doesn't exist."
  (with-temp-buffer
    (if (zerop (call-process "global" nil t nil "-pr"))
	(buffer-substring (point-min) (1- (point-max)))
      nil)))

(defun gtags-update ()
  "Make GTAGS incremental update"
  (call-process "global" nil nil nil "-u"))

(defun gtags-update-hook ()
  (when (gtags-root-dir)
    (gtags-update)))

(add-hook 'after-save-hook #'gtags-update-hook)
