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
    width: 450
    height: 500

    property alias mainDisplayText: teMainNumericDisplay.text
    signal numberClicked(string number);
    signal offClicked();

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
        anchors.centerIn: parent


        TextField {
            id: teMainNumericDisplay
            Layout.fillWidth: true
            Layout.row: 0
            Layout.column: 0
            readOnly: true
            text: "0"

            function setText(newText)
            {
                text = newText;
            }

            Layout.columnSpan: 4
            font.pointSize: 28
            horizontalAlignment: Text.AlignRight

        }

        Button {
            id: btCancelOperand
            y: 0
            Layout.row: 1
            Layout.column: 0
            width: height
            text: qsTr("C")
            font.pointSize: 24
            highlighted: false

        }

        Button {
            id: btCancelAll
            y: 0
            Layout.row: 1
            Layout.column: 1
            width: height
            text: qsTr("CA")
            font.pointSize: 24
            highlighted: false

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

            Button {
                id: btNumericOne
                y: 0
                Layout.row: 2
                Layout.column: 0
                width: height
                text: qsTr("1")
                font.pointSize: 24
                highlighted: false

                onClicked:
                {
                    numberClicked(text);
                }

            }

            Button {
                id: btNumericTwo
                width: height
                Layout.row: 2
                Layout.column: 1

                text: qsTr("2")
                highlighted: false
                font.pointSize: 24

                onClicked:
                {
                    numberClicked(text);
                }

            }

            Button {
                id: btNumericThree
                width: height
                Layout.row: 2
                Layout.column: 2
                text: qsTr("3")
                highlighted: false
                font.pointSize: 24

                onClicked:
                {
                    numberClicked(text);
                }

            }

            Button {
                id: btNumericFour
                width: height
                Layout.row: 3
                Layout.column: 0
                text: qsTr("4")
                highlighted: false
                font.pointSize: 24

                onClicked:
                {
                    numberClicked(text);
                }

            }

            Button {
                id: btNumericFive
                width: height
                Layout.row: 3
                Layout.column: 1
                text: qsTr("5")
                highlighted: false
                font.pointSize: 24

                onClicked:
                {
                    numberClicked(text);
                }

            }

            Button {
                id: btNumericSix
                width: height
                Layout.row: 3
                Layout.column: 2
                text: qsTr("6")
                highlighted: false
                font.pointSize: 24

                onClicked:
                {
                    numberClicked(text);
                }

            }
            Button {
                id: btNumericSeven
                width: height
                Layout.row: 4
                Layout.column: 0
                text: qsTr("7")
                highlighted: false
                font.pointSize: 24

                onClicked:
                {
                    numberClicked(text);
                }

            }

            Button {
                id: btNumericEight
                width: height
                Layout.row: 4
                Layout.column: 1
                text: qsTr("8")
                highlighted: false
                font.pointSize: 24

                onClicked:
                {
                    numberClicked(text);
                }

            }

            Button {
                id: btNumericNine
                width: height
                Layout.row: 4
                Layout.column: 2
                text: qsTr("9")
                highlighted: false
                font.pointSize: 24

                onClicked:
                {
                    numberClicked(text);
                }

            }
            Button {
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

            Button {
                id: btDot
                width: height
                Layout.row: 5
                Layout.column: 0

                text: qsTr(".")
                highlighted: false
                font.pointSize: 24

            }

            Button {
                id: btEqualsSign
                width: height
                Layout.row: 5
                Layout.column: 2

                text: qsTr("=")
                highlighted: false
                font.pointSize: 24

            }

            Button {
                id: btOperationPlus
                width: height
                Layout.row: 2
                Layout.column: 3

                text: qsTr("+")
                highlighted: false
                font.pointSize: 24

            }

            Button {
                id: btOperationMinus
                width: height
                Layout.row: 3
                Layout.column: 3

                text: qsTr("-")
                highlighted: false
                font.pointSize: 24

            }

            Button {
                id: btOperationMultiply
                width: height
                Layout.row: 4
                Layout.column: 3

                text: qsTr("*")
                highlighted: false
                font.pointSize: 24

            }

            Button {
                id: btOperationDivide
                width: height
                Layout.row: 5
                Layout.column: 3

                text: qsTr("/")
                highlighted: false
                font.pointSize: 24

            }

    }
}
