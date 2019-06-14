#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "funcionario.h"
#include <algorithm>
#include "empresa.h"
#include <QFileDialog>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void inserirNaTabela();
    void EstatisticasDaTabela();
    int i;
private slots:
    void on_bfuncionario_clicked();






    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_actionSalvar_triggered();

    void on_actionAbrir_triggered();

    void on_pushButton_6_clicked();

    void on_bfuncionario_2_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::MainWindow *ui;
    Funcionario funcionario;
    Funcionario funcionariot;
    Empresa funcionarios;

};

#endif // MAINWINDOW_H
