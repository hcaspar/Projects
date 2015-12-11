;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    .emacs                                             :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/12/11 10:19:23 by hcaspar           #+#    #+#              ;
;    Updated: 2015/12/11 10:25:26 by hcaspar          ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

;; Load general features files
(setq config_files "/usr/share/emacs/site-lisp/")
(setq load-path (append (list nil config_files) load-path))

(load "list.el")
(load "string.el")
(load "comments.el")
(load "header.el")

(autoload 'php-mode "php-mode" "Major mode for editing PHP code" t)
(add-to-list 'auto-mode-alist '("\\.php[34]?\\'\\|\\.phtml\\'" . php-mode))

;; Set default emacs configuration
(set-language-environment "UTF-8")
(setq-default tab-width 4)
(setq-default indent-tabs-mode t)
(global-set-key (kbd "DEL") 'backward-delete-char)
(setq-default c-backspace-function 'backward-delete-char)
(setq-default c-basic-offset 4)
(setq-default c-default-style "linux")
(setq-default tab-stop-list '(4 8 12 16 20 24 28 32 36 40 44 48 52 56 60
				64 68 72 76 80 84 88 92 96 100 104 108 112 116 120))

;; Display cursor column
(column-number-mode t)

;; Display useless spaces and tabs
(global-hi-lock-mode t)
(add-hook 'change-major-mode-hook '(lambda () (highlight-regexp "  +" 'hi-yellow)))
(add-hook 'change-major-mode-hook '(lambda () (highlight-regexp " +$" 'hi-green)))
(add-hook 'change-major-mode-hook '(lambda () (highlight-regexp "	+$" 'hi-blue)))

;; Change backup directory
(setq backup-directory-alist '("." . "~/.emacs.d/saves/"))