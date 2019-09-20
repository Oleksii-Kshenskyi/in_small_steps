import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Window 2.12
import QtQuick.Controls.Material 2.12
import QtQuick.Layouts 1.12
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
    signal dotClicked();

    function getDisplayText()
    {
        return mainDisplayText;
    }

    function setDisplayText(newText)
    {
        teMainNumericDisplay.setText(newText);
    }

    function getOperation(index)
    {
        var op = ["+", "-", "*", "/"];
        return op[index];
    }

    Shortcut {
        sequence: "0"
        onActivated: numberClicked("0")
    }

    Shortcut {
        sequence: "1"
        onActivated: numberClicked("1")
    }

    Shortcut {
        sequence: "2"
        onActivated: numberClicked("2")
    }

    Shortcut {
        sequence: "3"
        onActivated: numberClicked("3")
    }

    Shortcut {
        sequence: "4"
        onActivated: numberClicked("4")
    }

    Shortcut {
        sequence: "5"
        onActivated: numberClicked("5")
    }

    Shortcut {
        sequence: "6"
        onActivated: numberClicked("6")
    }

    Shortcut {
        sequence: "7"
        onActivated: numberClicked("7")
    }

    Shortcut {
        sequence: "8"
        onActivated: numberClicked("8")
    }

    Shortcut {
        sequence: "9"
        onActivated: numberClicked("9")
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

            Shortcut {
                sequence: "Ctrl+E"
                onActivated: clearEntryClicked()
            }

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

            Shortcut {
                sequence: "Ctrl+A"
                onActivated: clearAllClicked()
            }

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

            Shortcut {
                sequence: "Backspace"
                onActivated: eraseOneClicked()
            }

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

            Shortcut {
                sequence: "ESC"
                onActivated: offClicked()
            }
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

            onClicked: dotClicked();

            Shortcut {
                sequence: "."
                onActivated: dotClicked()
            }
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

            Shortcut {
                sequences: ["=", "Enter"]
                onActivated: equalsSignClicked()
            }
        }

        Repeater {
            model: 4

            Button {
                width: height
                Layout.row: 2 + index
                Layout.column: 3

                text: getOperation(index)
                highlighted: false
                font.pointSize: 24

                onClicked: operationClicked(getOperation(index))

                Shortcut {
                    sequence: getOperation(index)
                    onActivated: operationClicked(sequence)
                }
            }
        }

    }
}
