#!/usr/bin/env python3

import argparse
from lxml import etree
from jinja2 import Template

HTML_TEMPLATE = """
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <title>Google Test Report</title>
  <style>
    body { font-family: Arial, sans-serif; margin: 20px; }
    table { border-collapse: collapse; width: 100%; margin-bottom: 40px; }
    th, td { border: 1px solid #ccc; padding: 8px; text-align: left; }
    th { background-color: #f2f2f2; }
    .pass { color: green; }
    .fail { color: red; font-weight: bold; }
    .suite { margin-top: 40px; }
  </style>
</head>
<body>
  <h1>Google Test Report</h1>

  {% for suite in testsuites %}
    <div class="suite">
      <h2>Test Suite: {{ suite.name }}</h2>
      <table>
        <thead>
          <tr>
            <th>Test Name</th>
            <th>Status</th>
            <th>Time (s)</th>
            <th>Message</th>
          </tr>
        </thead>
        <tbody>
          {% for test in suite.tests %}
            <tr>
              <td>{{ test.name }}</td>
              <td class="{{ 'pass' if test.status == 'PASS' else 'fail' }}">{{ test.status }}</td>
              <td>{{ test.time }}</td>
              <td>{{ test.message }}</td>
            </tr>
          {% endfor %}
        </tbody>
      </table>
    </div>
  {% endfor %}
</body>
</html>
"""

def parse_gtest_xml(xml_path):
    tree = etree.parse(xml_path)
    root = tree.getroot()

    suites = []
    for ts in root.findall("testsuite"):
        suite = {
            "name": ts.attrib["name"],
            "tests": []
        }
        for tc in ts.findall("testcase"):
            status = "PASS"
            message = ""
            failure = tc.find("failure")
            if failure is not None:
                status = "FAIL"
                message = failure.attrib.get("message", "") + " " + failure.text if failure.text else ""
            suite["tests"].append({
                "name": tc.attrib["name"],
                "status": status,
                "time": tc.attrib.get("time", "0"),
                "message": message.strip()
            })
        suites.append(suite)
    return suites

def generate_html(testsuites, output_file):
    template = Template(HTML_TEMPLATE)
    html = template.render(testsuites=testsuites)
    with open(output_file, "w", encoding="utf-8") as f:
        f.write(html)

def main():
    parser = argparse.ArgumentParser(description="Convert Google Test XML to HTML")
    parser.add_argument("--input", required=True, help="Path to gtest XML report")
    parser.add_argument("--output", required=True, help="Output HTML file path")
    args = parser.parse_args()

    testsuites = parse_gtest_xml(args.input)
    generate_html(testsuites, args.output)
    print(f"HTML report generated at {args.output}")

if __name__ == "__main__":
    main()
