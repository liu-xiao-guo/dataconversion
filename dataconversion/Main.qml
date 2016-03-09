import QtQuick 2.0
import Ubuntu.Components 1.1

/*!
    \brief MainView with a Label and Button elements.
*/

MainView {
    // objectName for functional testing purposes (autopilot-qt5)
    objectName: "mainView"

    // Note! applicationName needs to match the "name" field of the click manifest
    applicationName: "dataconversion.liu-xiao-guo"

    /*
     This property enables the application to change orientation
     when the device is rotated. The default is false.
    */
    //automaticOrientation: true

    // Removes the old toolbar and enables new features of the new header.
    useDeprecatedToolbar: false

    width: units.gu(60)
    height: units.gu(85)

    function readValues(anArray, anObject) {
        for (var i = 0; i < anArray.length; i++ )
            console.log("Array item:", anArray[ i ])

        for (var prop in anObject) {
            console.log("Object item:", prop, "=", anObject[prop])
        }
    }

    Page {
        title: i18n.tr("dataconversion")

        Button {
            anchors.centerIn: parent

            text: "Call C++ to pass array and object"

            onClicked: {
                var i = {
                    "from" :  "xiaoguo.liu@company.com",
                    "to" :  "y@mail.com",
                    "message" : "This is teriffic!"
                };

                var j = ["Saab", "Volvo", "BMW"];

                myclass.callingFromQml(j, i);
            }
        }

    }
}

