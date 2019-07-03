pipeline {

  environment {
    major=0
    minor=1
    patch="${env.BUILD_ID}"
    name="${env.JOB_NAME}"
    version="$major.$minor.$patch"
    date=sh(returnStdout: true, script: 'date +"%Y-%m-%d"').trim()

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
      agent { label 'master'}
      steps {
        sh "make"
        sh "make coverage"
      }
      post {
        always {
          publishCppcheck pattern:'build/coverage/reports/cppcheck.xml'
          //junit 'build/test/reports/*.xml'
          //sh 'mkdir -p $publishCoberturaDir'
          //sh 'cp -r build/coverage/reports/*.html $publishCoberturaDir/'
        }
      }
    }

    //NO TEST YET
    /*stage('BUILD WINDOWS AND TEST'){
      agent {label 'windows10-x64-2'}
      steps {
        bat "Scripts\\change_makefile_name.bat"
        //compile
        bat "make"
        bat "make test"
      }
      post {
        always {
          junit 'build\\test\\reports\\*.xml'
        }
      }
    }*/

    stage('BUILD AND SIGN EXES'){
      agent {label 'windows10-x64-2'}
      steps {
        bat "Scripts\\change_makefile_name.bat"
        //compile
        bat "make"
        bat "call Scripts\\build_gui.bat"
        bat "call Scripts\\sign_exes.au3"
        bat "call Scripts\\package_gui.bat"
        archiveArtifacts('build\\bin\\dump852.exe')
        archiveArtifacts('build\\bin\\octave-dumper.exe')
        archiveArtifacts('build\\bin\\Dump852-GUI.zip')
      }
    }

    stage('BUILD MASTER'){
      agent { label 'master'}
      steps {
        sh "make"
        sh 'mkdir -p $binMasterPublishDir'
        sh 'cp -r build/bin/dump852 $binMasterPublishDir/dump852-$version'
        sh 'cp -r build/bin/octave-dumper $binMasterPublishDir/octave-dumper-$version'
      }
    }

    stage('SAVE WINDOWS EXE on SERVER'){
      agent { label 'master' }
      steps {
        sh 'mkdir -p $binWinx64PublishDir'
        sh 'cp /var/lib/jenkins/jobs/$name/builds/$patch/archive/build/bin/dump852.exe $binWinx64PublishDir/dump852-$version.exe'
        sh 'cp /var/lib/jenkins/jobs/$name/builds/$patch/archive/build/bin/octave-dumper.exe $binWinx64PublishDir/octave-dumper-$version.exe'
        sh 'cp /var/lib/jenkins/jobs/$name/builds/$patch/archive/build/bin/Dump852-GUI.zip $binWinx64PublishDir/Dump852-GUI-$version.zip'
      }
    }
  }
}
