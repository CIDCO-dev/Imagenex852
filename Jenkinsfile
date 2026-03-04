pipeline {

  environment {
    major=0
    minor=1
    patch="${env.BUILD_ID}"
    name="${env.JOB_NAME}"
    version="$major.$minor.$patch"

    publishDir="/var/www/html/$name/$version"
    lastPublishDir="/var/www/html/$name/last"
    binMasterPublishDir="$publishDir/bin/debian9"
    binWinx64Dir="bin/windows-x64"
    binWinx64PublishDir="$publishDir/$binWinx64Dir"
    publishCoberturaDir="/var/www/html/$name/$version/cobertura"
    publishDoxygenDir="/var/www/html/$name/$version/doxygen"
  }

  agent none
  stages {

    stage('TEST MASTER'){
      agent { label 'ubnt20-build-opensidescan-vm'}
      steps {
        //Initialize date variable for windows
        script{
          date= sh([ script: 'date +"%Y-%m-%d"', returnStdout: true]).trim()
        }
        sh "make"
        sh "make coverage"
      }
      post {
        always {
          publishCppcheck pattern:'build/coverage/reports/cppcheck.xml'
        }
      }
    }

    stage('BUILD AND SIGN EXES'){
      agent {label 'windows10-x64-2'}
      steps {
        bat "Scripts\\change_makefile_name.bat"
        //compile
        bat "make"
        bat "call Scripts\\build_gui.bat"
        bat "call Scripts\\sign_exes.au3"
        bat "call Scripts\\package_gui.bat"
        //Make installer
        bat "call Scripts\\build_and_package_for_installer.bat"
        bat "call Scripts\\set_date_and_version.bat %version% ${date}"
        bat "cd Installer & %binarycreator% -c config\\config.xml -p packages Imagenex852-Dump-Installer-%version%-windows.exe"
        bat "call Scripts\\sign_installer.au3 %version%"

        archiveArtifacts('build\\bin\\dump852.exe')
        archiveArtifacts('build\\bin\\octave-dumper.exe')
        archiveArtifacts('build\\gui\\Dump852-GUI.zip')
        archiveArtifacts('Installer\\*.exe')
      }
    }

    stage('BUILD MASTER'){
      agent { label 'ubnt20-build-opensidescan-vm'}
      steps {
        sh "make"
        sh 'mkdir -p $binMasterPublishDir'
        sh 'cp -r build/bin/dump852 $binMasterPublishDir/dump852-$version'
        sh 'cp -r build/bin/octave-dumper $binMasterPublishDir/octave-dumper-$version'
        sh 'Scripts/build_and_package_for_installer.sh'
        sh 'Scripts/set_date_and_version.sh $version'
        sh 'cd Installer && /opt/Qt/QtIFW-3.1.1/bin/binarycreator -c config/config.xml -p packages Imagenex852-Dump-Installer-$version.run'
        sh 'chmod +x Installer/Imagenex852-Dump-Installer-$version.run'
        sh 'cp -r Installer/Imagenex852-Dump-Installer-$version.run $binMasterPublishDir/Imagenex852-Dump-Installer-$version.run'
      }
    }

    stage('SAVE WINDOWS EXE on SERVER'){
      agent { label 'ubnt20-build-opensidescan-vm' }
      steps {
        sh 'mkdir -p $binWinx64PublishDir'
        sh 'cp /var/lib/jenkins/jobs/$name/builds/$patch/archive/build/bin/dump852.exe $binWinx64PublishDir/dump852-$version.exe'
        sh 'cp /var/lib/jenkins/jobs/$name/builds/$patch/archive/build/bin/octave-dumper.exe $binWinx64PublishDir/octave-dumper-$version.exe'
        sh 'cp /var/lib/jenkins/jobs/$name/builds/$patch/archive/build/gui/Dump852-GUI.zip $binWinx64PublishDir/Dump852-GUI-$version.zip'
        sh 'cp /var/lib/jenkins/jobs/$name/builds/$patch/archive/Installer/Imagenex852-Dump-Installer-$version-windows.exe $binWinx64PublishDir/Imagenex852-Dump-Installer-$version-windows.exe'
      }
    }
  }
}
