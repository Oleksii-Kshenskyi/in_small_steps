import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Window 2.3
import QtQuick.Controls.Material 2.2
import QtQuick.Layouts 1.3
import Qt.labs.calendar 1.0
import QtQuick.Controls.Styles 1.4


Item {
    id: frmMainForm

    visible: true
    width: 470
    height: 500

    property alias mainDisplayText: teMainNumericDisplay.text
    property alias mainDisplayLength: teMainNumericDisplay.maximumLength
    signal numberClicked(string number);
    signal offClicked();
    signal clearEntryClicked();
    signal clearAllClicked();
    signal eraseOneClicked();
    signal operationClicked(string operation);
    signal equalsSignClicked();

    function getDisplayText()
    {
        return mainDisplayText;
    }

    function setDisplayText(newText)
    {
        teMainNumericDisplay.setText(newText);
    }

    GridLayout {
        id: grid
        anchors.fill: parent
        anchors.topMargin: 30
        anchors.leftMargin: 30
        anchors.bottomMargin: 30
        anchors.rightMargin: 30


        TextField {
            id: teMainNumericDisplay
            Layout.fillWidth: true
            Layout.row: 0
            Layout.column: 0
            readOnly: true
            text: "0"
            maximumLength: 26

            function setText(newText)
            {
                text = newText;
            }

            Layout.columnSpan: 4
            font.pointSize: 20
            horizontalAlignment: Text.AlignRight

        }

        Button {
            id: btClearEntry
            y: 0
            Layout.row: 1
            Layout.column: 0
            width: height
            text: qsTr("CE")
            font.pointSize: 24
            highlighted: false

            onClicked: clearEntryClicked();

        }

        Button {
            id: btClearAll
            y: 0
            Layout.row: 1
            Layout.column: 1
            width: height
            text: qsTr("CA")
            font.pointSize: 24
            highlighted: false

            onClicked: clearAllClicked();

        }

        Button {
            id: btEraseOne
            y: 0
            Layout.row: 1
            Layout.column: 2
            width: height
            text: qsTr("\u2190")
            font.pointSize: 24
            highlighted: false

            onClicked: eraseOneClicked();

        }

        Button {
            id: btOFF
            y: 0
            Layout.row: 1
            Layout.column: 3
            width: height
            text: qsTr("OFF")
            font.pointSize: 24
            highlighted: false

            onClicked: offClicked();
        }

        Repeater
        {
            model: 9
            Button
            {
                Layout.row: 2 + Math.floor(index / 3)
                Layout.column: index % 3
                width: height
                text: (Layout.row === 2) ? index + 7 : ((Layout.row === 3) ? index + 1 : index - 5)
                font.pointSize: 24
                highlighted: false

                onClicked:
                {
                    numberClicked(text);
                }
            }
        }

        Button
        {
            id: btNumericZero
            width: height
            Layout.row: 5
            Layout.column: 1
            text: qsTr("0")
            highlighted: false
            font.pointSize: 24

            onClicked:
            {
                numberClicked(text);
            }
        }

        Button
        {
            id: btDot
            width: height
            Layout.row: 5
            Layout.column: 0

            text: qsTr(".")
            highlighted: false
            font.pointSize: 24
        }

        Button
        {
            id: btEqualsSign
            width: height
            Layout.row: 5
            Layout.column: 2

            text: qsTr("=")
            highlighted: false
            font.pointSize: 24

            onClicked: equalsSignClicked();
        }

        Button
        {
            id: btOperationPlus
            width: height
            Layout.row: 2
            Layout.column: 3

            text: qsTr("+")
            highlighted: false
            font.pointSize: 24

            onClicked: operationClicked("add");
        }

        Button
        {
            id: btOperationMinus
            width: height
            Layout.row: 3
            Layout.column: 3

            text: qsTr("-")
            highlighted: false
            font.pointSize: 24

            onClicked: operationClicked("sub");
        }

        Button
        {
            id: btOperationMultiply
            width: height
            Layout.row: 4
            Layout.column: 3

            text: qsTr("*")
            highlighted: false
            font.pointSize: 24

            onClicked: operationClicked("mul");
        }

        Button
        {
            id: btOperationDivide
            width: height
            Layout.row: 5
            Layout.column: 3

            text: qsTr("/")
            highlighted: false
            font.pointSize: 24

            onClicked: operationClicked("div");
        }
    }
}
