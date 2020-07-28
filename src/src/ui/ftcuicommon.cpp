/*
* Copyright (c) 2020 Hunesion Inc.
*
* This library is free software; you can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public
* License as published by the Free Software Foundation; 
* either version 2.1 of the License, or (at your option) any later version.
* See the file COPYING included with this distribution for more information.
* https://github.com/HuneOpenUp/ossFileTransferClient/blob/master/COPYING
*/


#include "ftcuicommon.h"


bool        
ftc_ui_is_internal_location()
{
    bool rv = false;

    if (Ftc::Core::GlobalVar::getLoginLocation().getLocation() == "1") {
        rv = true;
    } 

    return rv;
}

GtkResponseType        
ftc_ui_message_box(GtkMessageType type, GtkButtonsType buttons, const char *message)
{
    GtkWidget *msg_dlg = gtk_message_dialog_new(GTK_WINDOW(ftc_ui_get_main_window()), GTK_DIALOG_MODAL, type, buttons, message, NULL);
    GtkResponseType rv = (GtkResponseType)gtk_dialog_run(GTK_DIALOG(msg_dlg));
    if (msg_dlg) {
        gtk_widget_destroy(msg_dlg);
        msg_dlg = NULL;
    }
    return rv;
}

