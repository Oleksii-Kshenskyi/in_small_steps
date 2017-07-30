import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 450
    height: 500
    title: qsTr("MVC Calculator")
    minimumHeight: height
    minimumWidth: width
    maximumHeight: height
    maximumWidth: width


    CalcForm {
        anchors.fill: parent

    }
}
