#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    Pintor = new pintor(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_clicked(){


    QString valorStr = ui->lineEdit_2->text();
    QString posStr = ui->lineEdit->text();

    //revisar que no este vacio
    if (valorStr.isEmpty() || posStr.isEmpty()) {
        QMessageBox::warning(this, "Error", "Debe ingresar valor y posición.");
        return; // No continúa
    }

    int valor = valorStr.toInt();
    int pos = posStr.toInt();

    // Validar posición según tamaño actual
    if (pos < 0 || pos > lista.getSize()) {
        QMessageBox::warning(this, "Error", "La posición no es válida.");
        return;
    }


    // Validar caso de lista vacía
    if (lista.getSize() == 0 && pos != 0) {
        QMessageBox::warning(this, "Error", "Si la lista está vacía, solo puede insertar en posición 0.");
        return;
    }

    if (lista.insertarCola(valor, pos)) {
        Pintor->dibujar(lista);
    }

    ui->lineEdit_2->clear();
    ui->lineEdit->clear();
}






void MainWindow::on_pushButton_2_clicked()
{
    QString valorStr = ui->valBorrar->text();

    // que no este vacio los espacios
    if (valorStr.isEmpty()) {
        QMessageBox::warning(this, "Error", "Debe ingresar un valor para eliminar.");
        return;
    }

    // que la lista no este vacia
    if (lista.getSize() == 0) {
        QMessageBox::warning(this, "Error", "La lista está vacía, no hay nada que eliminar.");
        return;
    }

    int valor = valorStr.toInt();

    // Llamar al backend para eliminar
    if (lista.borrar(valor)) {
        // Redibujar lista actualizada
        Pintor->dibujar(lista);
    } else {
        QMessageBox::warning(this, "Error", "El valor no se encontró en la lista.");
    }

    // Limpiar campo
    ui->valBorrar->clear();
}




void MainWindow::on_pushButton_3_clicked()
{
    QString valorStr = ui->valBuscar->text();
    if (valorStr.isEmpty()) {
        QMessageBox::warning(this, "Error", "Debe ingresar un valor para buscar.");
        return;
    }

    int valor = valorStr.toInt();
    int pos = lista.buscar(valor);

    if (pos == -1) {
        QMessageBox::information(this, "Resultado", "El valor NO se encontró en la lista.");
        Pintor->dibujar(lista);  // dibuja sin resaltar
    } else {
        //QMessageBox::information(this, "Resultado", "El valor fue encontrado y se resaltará.");
        Pintor->dibujarConResaltado(lista, pos);  // dibuja con nodo resaltado
    }

    ui->valBuscar->clear();
}


