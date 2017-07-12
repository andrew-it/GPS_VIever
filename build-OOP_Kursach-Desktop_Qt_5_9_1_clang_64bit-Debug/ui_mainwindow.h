/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *action_2;
    QAction *action_3;
    QAction *action_4;
    QAction *action_6;
    QAction *action_7;
    QAction *action_9;
    QAction *action_11;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_6;
    QGraphicsView *graphicsView;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelOfPT;
    QLabel *labelOfPointType_2;
    QFrame *line_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QDoubleSpinBox *SpinBoxHeight;
    QFrame *line_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *lineEditOfLatitude;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLineEdit *lineEditOfLongitude;
    QFrame *line_4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QDateEdit *dateEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QTimeEdit *timeEdit;
    QFrame *line;
    QCheckBox *colorCheckBox;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(973, 666);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QStringLiteral("action_2"));
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QStringLiteral("action_3"));
        action_4 = new QAction(MainWindow);
        action_4->setObjectName(QStringLiteral("action_4"));
        action_6 = new QAction(MainWindow);
        action_6->setObjectName(QStringLiteral("action_6"));
        action_7 = new QAction(MainWindow);
        action_7->setObjectName(QStringLiteral("action_7"));
        action_9 = new QAction(MainWindow);
        action_9->setObjectName(QStringLiteral("action_9"));
        action_11 = new QAction(MainWindow);
        action_11->setObjectName(QStringLiteral("action_11"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy1);
        graphicsView->setMinimumSize(QSize(800, 400));

        horizontalLayout_6->addWidget(graphicsView);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setSizeConstraint(QLayout::SetFixedSize);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        labelOfPT = new QLabel(centralWidget);
        labelOfPT->setObjectName(QStringLiteral("labelOfPT"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(labelOfPT->sizePolicy().hasHeightForWidth());
        labelOfPT->setSizePolicy(sizePolicy2);

        horizontalLayout_5->addWidget(labelOfPT);

        labelOfPointType_2 = new QLabel(centralWidget);
        labelOfPointType_2->setObjectName(QStringLiteral("labelOfPointType_2"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(labelOfPointType_2->sizePolicy().hasHeightForWidth());
        labelOfPointType_2->setSizePolicy(sizePolicy3);

        horizontalLayout_5->addWidget(labelOfPointType_2);


        verticalLayout_4->addLayout(horizontalLayout_5);

        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy4);

        verticalLayout_3->addWidget(label);

        SpinBoxHeight = new QDoubleSpinBox(centralWidget);
        SpinBoxHeight->setObjectName(QStringLiteral("SpinBoxHeight"));
        SpinBoxHeight->setMaximum(10000);

        verticalLayout_3->addWidget(SpinBoxHeight);


        verticalLayout_4->addLayout(verticalLayout_3);

        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(label_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);
        label_3->setMinimumSize(QSize(25, 0));

        horizontalLayout->addWidget(label_3);

        lineEditOfLatitude = new QLineEdit(centralWidget);
        lineEditOfLatitude->setObjectName(QStringLiteral("lineEditOfLatitude"));
        QSizePolicy sizePolicy5(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(lineEditOfLatitude->sizePolicy().hasHeightForWidth());
        lineEditOfLatitude->setSizePolicy(sizePolicy5);
        lineEditOfLatitude->setMinimumSize(QSize(115, 0));

        horizontalLayout->addWidget(lineEditOfLatitude);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);
        label_4->setMinimumSize(QSize(25, 0));

        horizontalLayout_2->addWidget(label_4);

        lineEditOfLongitude = new QLineEdit(centralWidget);
        lineEditOfLongitude->setObjectName(QStringLiteral("lineEditOfLongitude"));
        sizePolicy5.setHeightForWidth(lineEditOfLongitude->sizePolicy().hasHeightForWidth());
        lineEditOfLongitude->setSizePolicy(sizePolicy5);
        lineEditOfLongitude->setMinimumSize(QSize(115, 0));

        horizontalLayout_2->addWidget(lineEditOfLongitude);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_4->addLayout(verticalLayout);

        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy2.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(label_5);

        dateEdit = new QDateEdit(centralWidget);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        sizePolicy5.setHeightForWidth(dateEdit->sizePolicy().hasHeightForWidth());
        dateEdit->setSizePolicy(sizePolicy5);
        dateEdit->setMinimumSize(QSize(100, 0));

        horizontalLayout_3->addWidget(dateEdit);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy2.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy2);

        horizontalLayout_4->addWidget(label_6);

        timeEdit = new QTimeEdit(centralWidget);
        timeEdit->setObjectName(QStringLiteral("timeEdit"));
        sizePolicy5.setHeightForWidth(timeEdit->sizePolicy().hasHeightForWidth());
        timeEdit->setSizePolicy(sizePolicy5);
        timeEdit->setMinimumSize(QSize(100, 0));

        horizontalLayout_4->addWidget(timeEdit);


        verticalLayout_2->addLayout(horizontalLayout_4);


        verticalLayout_4->addLayout(verticalLayout_2);

        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        QSizePolicy sizePolicy6(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy6);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line);

        colorCheckBox = new QCheckBox(centralWidget);
        colorCheckBox->setObjectName(QStringLiteral("colorCheckBox"));
        sizePolicy4.setHeightForWidth(colorCheckBox->sizePolicy().hasHeightForWidth());
        colorCheckBox->setSizePolicy(sizePolicy4);
        colorCheckBox->setChecked(false);
        colorCheckBox->setTristate(false);

        verticalLayout_4->addWidget(colorCheckBox);


        horizontalLayout_6->addLayout(verticalLayout_4);


        gridLayout->addLayout(horizontalLayout_6, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 973, 21));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(action);
        menu->addAction(action_2);
        menu->addSeparator();
        menu->addAction(action_11);
        menu_2->addAction(action_3);
        menu_2->addAction(action_4);
        menu_3->addAction(action_9);
        menu_3->addSeparator();
        menu_3->addAction(action_7);
        menu_3->addAction(action_6);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\276\321\200 \321\202\321\200\320\265\320\272\320\276\320\262", Q_NULLPTR));
        action->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", Q_NULLPTR));
        action_2->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", Q_NULLPTR));
        action_3->setText(QApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", Q_NULLPTR));
        action_4->setText(QApplication::translate("MainWindow", "\320\244\321\203\320\275\320\272\321\206\320\270\320\276\320\275\320\260\320\273\321\214\320\275\320\276\321\201\321\202\321\214", Q_NULLPTR));
        action_6->setText(QApplication::translate("MainWindow", "\320\223\321\200\320\260\321\204\320\270\320\272 \320\262\321\213\321\201\320\276\321\202\321\213", Q_NULLPTR));
        action_7->setText(QApplication::translate("MainWindow", "\320\223\321\200\320\260\321\204\320\270\320\272 \321\201\320\272\320\276\321\200\320\276\321\201\321\202\320\270", Q_NULLPTR));
        action_9->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\202\320\276\321\207\320\272\321\203 \320\272 \321\202\321\200\320\265\320\272\321\203", Q_NULLPTR));
        action_11->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214 \320\264\320\276\320\272\321\203\320\274\320\265\320\275\321\202", Q_NULLPTR));
        labelOfPT->setText(QApplication::translate("MainWindow", "\320\242\320\270\320\277 \321\202\320\276\321\207\320\272\320\270:", Q_NULLPTR));
        labelOfPointType_2->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\201\321\202\320\276\321\202\320\260 \320\275\320\260\320\264 \321\203\321\200\320\276\320\262\320\275\320\265\320\274 \320\274\320\276\321\200\321\217:", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\213:", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\320\241.\320\250.", Q_NULLPTR));
        lineEditOfLatitude->setInputMask(QApplication::translate("MainWindow", "99.9999999", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\320\222.\320\224.", Q_NULLPTR));
        lineEditOfLongitude->setInputMask(QApplication::translate("MainWindow", "99.9999999", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260:", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\321\217:", Q_NULLPTR));
        timeEdit->setDisplayFormat(QApplication::translate("MainWindow", "HH:mm:ss", Q_NULLPTR));
        colorCheckBox->setText(QApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \321\202\320\276\321\207\320\272\320\270 \320\277\320\276 \320\262\321\213\321\201\320\276\321\202\320\265", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("MainWindow", "\320\237\320\276\320\274\320\276\321\211\321\214", Q_NULLPTR));
        menu_3->setTitle(QApplication::translate("MainWindow", "\320\242\321\200\320\265\320\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
