import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.2

import WiFi 1.0

Page {
    id: wifiPage
    width: 640
    height: 400
    background: Rectangle {
        color: "#36393F"
    }

    Frame {
        anchors.fill: parent
        Flickable {
            id: flickable
            anchors.fill: parent
            anchors.bottomMargin: 0
            flickableDirection: Flickable.VerticalFlick

              ListView {
                  id: listView
                  anchors.fill: parent
            /*    onDragEnded:  {
                    console.log("ondragended")
                    console.log("ListView ContentY: " + listView.contentY)
                    if (header.refresh) {
                        console.log("Reload data...")

                    }
                }

                ReloadHeader {
                    id: header
                    y: -listView.contentY - height
                }
                anchors.fill: parent
                anchors.rightMargin: 10
                anchors.leftMargin: 10
                clip: true
                spacing: 10
                */

                model: WiFiModel {
                    list: wifiData
                }

                delegate: RowLayout {
                    width: listView.width
//                    anchors.left: parent.left
//                    anchors.right: parent.right

                    Frame {
                        implicitWidth: parent.width
                        background: Rectangle {
                            color: "transparent"
                            border.color: "#ffffff"
                            radius: 5
                        }


//                        Text {
//                            id: titleText
//                            text: model.title
//                            anchors.top: parent.top
//                            anchors.topMargin: -10
//                            lineHeight: 1.2
//                        }

                        Text {
                            id: ssidText
                            text: model.ssid
//                            anchors.top: titleText.bottom
//                            anchors.bottom: parent.bottom
                            anchors.fill: parent
                            wrapMode: Text.WordWrap
                            lineHeight: 1.2
                            color: "white"

                        }
                    }
                }

    //                states: [
    //                            State {
    //                                id: downRefresh
    //                                name: "downRefresh"; when: (listView.contentHeight > 0) && (listView.contentY > (listView.contentHeight - root.height + nPullHeight))
    //                                StateChangeScript {
    //                                    name: "funDownRefresh"
    //                                    script: funDownRefresh()
    //                                }
    //                            },
    //                            State {
    //                                id: upRefresh
    //                                name: "upRefresh"; when: (listView.contentY < -nPullHeight)
    //                                StateChangeScript {
    //                                    name: "funUpRefresh"
    //                                    script: funUpRefresh()
    //                                }
    //                            }
    //                        ]
                }
            }
  }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:4}
}
##^##*/
