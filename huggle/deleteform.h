//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.

#ifndef DELETEFORM_H
#define DELETEFORM_H

#include <QDialog>
#include <QTimer>
#include <QString>
#include <QtXml>
#include <QUrl>
#include "configuration.h"
#include "wikipage.h"
#include "apiquery.h"
#include "core.h"

namespace Ui
{
    class DeleteForm;
}

namespace Huggle
{
	class WikiPage;
    //! This is a delete form
    class DeleteForm : public QDialog
    {
        Q_OBJECT

    public:
        explicit DeleteForm(QWidget *parent = 0);
        ~DeleteForm();
		void setPage(WikiPage *Page);
	private slots:
		void on_pushButton_clicked();
		void on_pushButton_2_clicked();
		void onTick();
    private:
        Ui::DeleteForm *ui;
        WikiPage *page;
        QString deletetoken;
        ApiQuery *delquery;
        ApiQuery *tokenquery;
		//! Set the page to delete
		QTimer *dt;
		int delQueryPhase;
        void getToken();
        void Delete();
        void checkDelToken();
        void Failed(QString reason);
    };
}

#endif // DELETEFORM_H
